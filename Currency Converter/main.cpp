// currency_converter.cpp
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Box.H>

#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using std::string;
using std::ostringstream;
using std::unordered_map;
using std::vector;

struct App {
    Fl_Window*          win{};
    Fl_Input*           amount{};
    Fl_Choice*          from{};
    Fl_Choice*          to{};
    Fl_Output*          result{};
    Fl_Text_Display*    history{};
    Fl_Text_Buffer*     history_buf{};

    unordered_map<string,double> rate{
        {"USD",1.00},{"EUR",0.92},{"GBP",0.79},{"JPY",149.50},
        {"INR",83.00},{"CAD",1.36},{"AUD",1.52}
    };
    vector<string> hist;
};

static string selected(const Fl_Choice* c) {
    const char* t = c->text();
    if (!t) return string();
    return strlen(t) > 3 ? string(t, 3) : string(t);
}

static void push_history(App* app, const string& line, size_t keep = 80) {
    app->hist.push_back(line);
    if (app->hist.size() > keep) app->hist.erase(app->hist.begin());

    ostringstream oss;
    for (const auto& s : app->hist) oss << s << '\n';
    app->history_buf->text(oss.str().c_str());

    // Auto-scroll to newest entry
    app->history->insert_position(app->history_buf->length());
    app->history->show_insert_position();
}

static void on_convert(Fl_Widget*, void* ud) {
    auto* app = static_cast<App*>(ud);

    const char* a = app->amount->value();
    double amt = (a && *a) ? atof(a) : 0.0;

    string f = selected(app->from);
    string t = selected(app->to);
    if (!app->rate.count(f) || !app->rate.count(t)) return;

    double fx  = app->rate[t] / app->rate[f];
    double res = amt * fx;

    ostringstream os; os << std::fixed << std::setprecision(2) << res;
    app->result->value(os.str().c_str());

    ostringstream line;
    line << std::fixed << std::setprecision(2)
         << amt << ' ' << f << " = " << res << ' ' << t
         << "  (rate " << std::setprecision(6) << fx << ' ' << t << '/' << f << ')';
    push_history(app, line.str());
}

static void on_swap(Fl_Widget*, void* ud) {
    auto* app = static_cast<App*>(ud);
    int iF = app->from->value(), iT = app->to->value();
    if (iF >= 0 && iT >= 0) { app->from->value(iT); app->to->value(iF); }
}

int main(int argc, char** argv) {
    // Modern theme & base styling
    Fl::scheme("gleam");                         // try "gtk+", "plastic", "oxflat" too
    Fl::background(246, 248, 252);               // light window bg
    Fl::foreground(28, 28, 30);                  // label color
    Fl::set_font(FL_HELVETICA, "Segoe UI");      // nicer Windows font
    Fl::set_font(FL_COURIER,   "Consolas");      // monospaced font

    App app;

    // Window
    app.win = new Fl_Window(720, 460, "Currency Converter");
    app.win->color(fl_rgb_color(246, 248, 252));

    // Header brand bar
    auto* header = new Fl_Box(FL_FLAT_BOX, 0, 0, app.win->w(), 48, "Currency Converter");
    header->labelsize(18);
    header->labelfont(FL_HELVETICA_BOLD);
    header->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);
    header->color(fl_rgb_color(235, 240, 250));
    header->labelcolor(fl_rgb_color(35, 40, 55));

    // Layout metrics
    int top_pad = 56;                  // header height + spacing
    int x = 24, y = top_pad, labw = 120, w = 520, h = 32, gap = 40;

    // Label helper
    auto set_label = [](Fl_Widget* w){ w->labelsize(14); };

    // Button style helper
    auto style_button = [](Fl_Button* b){
        b->labelsize(14);
        b->box(FL_ROUNDED_BOX);
        b->color(fl_rgb_color(230, 235, 245));            // bg
        b->selection_color(fl_rgb_color(88,129,245));     // press/hover accent
    };

    // Amount
    auto* labAmt = new Fl_Box(FL_NO_BOX, x, y, labw, h, "Amount:");
    set_label(labAmt);
    app.amount = new Fl_Input(x + labw + 10, y, w, h);
    app.amount->textsize(14);
    app.amount->value("100");

    // From
    auto* labFrom = new Fl_Box(FL_NO_BOX, x, y += gap, labw, h, "From:");
    set_label(labFrom);
    app.from = new Fl_Choice(x + labw + 10, y, w, h);
    app.from->textsize(14);

    const char* opts[] = {"USD $","EUR €","GBP £","JPY ¥","INR ₹","CAD $","AUD $"};
    for (auto c : opts) app.from->add(c);
    app.from->value(0); // USD

    // To
    auto* labTo = new Fl_Box(FL_NO_BOX, x, y += gap, labw, h, "To:");
    set_label(labTo);
    app.to = new Fl_Choice(x + labw + 10, y, w, h);
    app.to->textsize(14);
    for (auto c : opts) app.to->add(c);
    app.to->value(1); // EUR

    // Buttons
    auto* btnConvert = new Fl_Button(x + labw + 10, y += gap, 150, h, "Convert");
    style_button(btnConvert);
    btnConvert->callback(on_convert, &app);

    auto* btnSwap = new Fl_Button(x + labw + 10 + 160, y, 150, h, "Swap");
    style_button(btnSwap);
    btnSwap->callback(on_swap, &app);

    // Result
    auto* labRes = new Fl_Box(FL_NO_BOX, x, y += gap, labw, h, "Result:");
    set_label(labRes);
    app.result = new Fl_Output(x + labw + 10, y, w, h);
    app.result->textsize(14);
    app.result->box(FL_BORDER_BOX);
    app.result->color(FL_WHITE);

    // History (scrollable)
    auto* labHist = new Fl_Box(FL_NO_BOX, x, y += gap, labw, h, "History:");
    set_label(labHist);
    app.history     = new Fl_Text_Display(x + labw + 10, y, w, 150);
    app.history_buf = new Fl_Text_Buffer();
    app.history->buffer(app.history_buf);
    app.history->box(FL_BORDER_BOX);
    app.history->color(FL_WHITE);
    app.history->textfont(FL_COURIER);
    app.history->textsize(13);

    // Resizable content
    app.win->resizable(app.history);

    app.win->end();
    app.win->show(argc, argv);
    return Fl::run();
}