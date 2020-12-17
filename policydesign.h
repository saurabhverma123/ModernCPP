#ifndef POLICYDESIGN
#define POLICYDESIGN

#endif // POLICYDESIGN

class OutputToCout
{
public:
    void print( string msg)
    {
        cout << msg << endl;
        cout << "OutputToCout::print" << endl;
    }
};

class OutputToFile
{
public:
    void print( string msg)
    {
        cout << msg << endl;
        cout << "OutputToFile::print" << endl;
    }
};

class LanguageEng
{
public:
    string message()
    {
        cout << "LanguageEng::message" << endl;
        return string("English message");
    }
};

class LanguageGer
{
public:
    string message()
    {
        cout << "LanguageGer::message" << endl;
        return string("Ger message");
    }
};

template < typename Language, typename OutputTo>
class Greeting : public Language, public OutputTo
{
    using Language::message;
    using OutputTo::print;
public:
    void run(){
        print(message());
    }
};

