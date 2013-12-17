#include <iostream>
#include <vector>
#include <functional>

class A {
    public:
    void notify() { std::cout << "A::notify()" << std::endl; }
};
class B {
    public:
    void attach( std::function<void()> func ) {
        notify_list_.push_back( func );
    }
    
    void sendEvent() {
        for( auto& f : notify_list_ ) {
            f();
        }
    }
    private:
    std::vector< std::function<void()> > notify_list_;
};

int main()
{
    A a;
    B b;
    auto f = std::bind(&A::notify,a);
    b.attach(f);
    
    b.sendEvent();
    
    return 0;
}
