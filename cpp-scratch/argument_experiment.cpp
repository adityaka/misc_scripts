#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class BaseArgument {
public:
    BaseArgument(){}
    ~BaseArgument(){}
};

template<typename ArgType>
class Argument : public BaseArgument{
private:
    ArgType val;
public:
    Argument(ArgType value){
        val = value;
    }

    ArgType GetValue(){
        return val;
    }

};


int main(int argc, char *argv[]){
    vector<BaseArgument*> v;
    auto arg1 = Argument<int>(argc);
    v.push_back(&arg1);
    Argument<int> *a = (Argument<int>*)v[0];
    cout << " Value inseted in vector " << a->GetValue() << endl;
    cout << "Base Type " << typeid(BaseArgument*).name() << endl;
    cout << "Argument Type " << typeid(Argument<int>*).name()<<endl;
    return 0;

}
