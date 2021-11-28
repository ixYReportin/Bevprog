#include "std_lib_facilities.h"

class Token{
public:
    char kind;
    double value;
    Token(char ch)
        :kind(ch), value(0) { }
    Token(char ch, double val)
        :kind(ch),value(val) { }
};

class Token_stream {
public:
    Token_stream();
    Token get();
    void putback(Token t);
private:
    bool full;
    Token buffer;
};

Token_stream::Token_stream()
    :full(false), buffer(0)
{
}

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;
    full = true;
}

Token Token_stream::get()
{
    if (full) {
        
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;

    switch (ch) {
    case '=':
    case 'x':
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(ch);
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token('8',val);
    }
    default:
        error("Rossz token");
    }
}

Token_stream ts;

double expression();

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' elvárt");
        return d;
    }
    case '8':
        return t.value;
    default:
        error("Primary elvárt");
    }
}

double term()
{
    double left = primary();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("nullával való osztás");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

double expression()
{
    double left = term();
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

int main()
try {
    cout << "Welcome to our simple calculator.\n";
    cout << "Please enter expressions using floating point numbers.\n";
    cout << "Useable mathematical signs: +, -, *, /, ().\n";
    cout << "For the result of an equation, press '='. If you wish to exit, press 'x'\n";
    while (cin) {
        cout << "> ";
        Token t = ts.get();
        while (t.kind == '=') t = ts.get();
        if (t.kind == 'x') {
            keep_window_open();
            return 0;
        }
        ts.putback(t);
        cout << "= " << expression() << endl;
    }
    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open("~~");
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open("~~");
    return 2;
}