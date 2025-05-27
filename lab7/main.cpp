#include <iostream>
#include <string>

using namespace std;

#define ABC 0
#define PART 2

#if PART == 1
#define PART1
#elif PART == 2
#define PART2
#endif

#ifdef PART1
class Word {
protected:
    string word;

public:
    static int i;

    Word()
    {
        cout << "constructor Word()\n";
    }
    Word(string wrd)
    {
        cout << "constructor Word()\n";
        word = wrd;
    }
    friend ostream& operator<<(ostream& out, const Word& self)
    {
        return out << self.word << endl;
    }
    ~Word()
    {
        cout << "destructor Word()\n";
    }
};

class String : public Word {
    int wordCount;

public:
    String()
        : Word()
        , wordCount(0)
    {
        cout << "constructor String()\n";
    }
    String(string wrd)
        : Word(wrd)
    {
        cout << "constructor String()\n";
        wordCount = getWordCount();
    }
    ~String()
    {
        cout << "destructor String()\n";
    }
    int getWordCount()
    {
        bool newWord = true;
        int count = 0;
        for (auto& c : word) {
            if (c == ' ') {
                newWord = 1;
            } else if (newWord) {
                count++;
                newWord = false;
            }
        }
        return count;
    }
    friend ostream& operator<<(ostream& out, const String& self)
    {
        return out << self.word << " (" << self.wordCount << " words)" << endl;
    }
};

int Word::i = 123;
#endif

#ifdef PART2
class Person {
protected:
    string name, surname;
    int age;

public:
    Person()
        : age(0)
    {
    }
    Person(string nm, string surnm, int ag)
        : name(nm)
        , surname(surnm)
        , age(ag)
    {
    }

    virtual void printInfo()
#if ABC
        = 0;
#else
    {
        cout << "Person(name=\"" << name;
        cout << "\", surname=\"" << surname;
        cout << "\", age=" << age << ")\n";
    }
#endif
};

class Worker : public Person {
protected:
    string specialty;

public:
    Worker()
        : Person()
    {
    }
    Worker(string nm, string surnm, int ag, string spec)
        : Person(nm, surnm, ag)
        , specialty(spec)
    {
    }

    virtual void printInfo()
    {
        cout << "Worker(name=\"" << name;
        cout << "\", surname=\"" << surname;
        cout << "\", age=" << age;
        cout << ", specialty=\"" << specialty << "\")\n";
    }
};

class Student : public Worker {
    string group;
    double meanGrade;

public:
    Student()
        : Worker()
        , meanGrade(0.0)
    {
    }

    Student(string nm, string surnm, int ag, string spec, string gr, double mean)
        : Worker(nm, surnm, ag, spec)
        , group(gr)
        , meanGrade(mean)
    {
    }
    virtual void printInfo()
    {
        cout << "Student(name=\"" << name;
        cout << "\", surname=\"" << surname;
        cout << "\", age=" << age;
        cout << ", specialty=\"" << specialty;
        cout << "\", group=\"" << group;
        cout << "\", meanGrade=" << meanGrade << ")\n";
    }
};
#endif

int main()
{
#ifdef PART1
    Word w("wrd");

    String s("some words with spaces");

    cout << s;
#endif
#ifdef PART2

    Student Andrew("Andrey", "Tikhonov", 19, "IVT", "IVT-42-23", 4.5);
    Andrew.printInfo();

    Person* personPtr = &Andrew;
    Worker* workerPtr = static_cast<Worker*>(personPtr);
    Student* studentPtr = static_cast<Student*>(personPtr);

    personPtr->printInfo();
    workerPtr->printInfo();
    studentPtr->printInfo();

    Person& personRef = Andrew;
    Worker& workerRef = static_cast<Worker&>(personRef);
    Student& studentRef = static_cast<Student&>(workerRef);

    personRef.printInfo();
    workerRef.printInfo();
    studentRef.printInfo();

#endif

    return 0;
}