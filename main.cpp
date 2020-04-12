/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */ 

#include <iostream>
#include <string>

struct T
{
    float value;
    std::string name;
    T(float v, const char* n) : value (v), name(n) {}
};

struct MinHeight
{
    T& compare(T& a, T& b)
    {
        /*  B. Self, 4/12/2020
        Suggesting scenario of both values being equal is outside the scope of this exercise.
        If this case was relevant however, might handle using epsilon check such as the following:
        if (std::abs(a.value - b.value) < 0.001f)       // handle case of both values being equal
        */
        return (a.value < b.value) ? a : b;
    }
};

struct U
{
    float setpoint {0}, processVariable {0};

    float controlMF(float & setpointTarget)
    {
        this->setpoint = setpointTarget;
        std::cout << "U's setpoint updated value: " << this->setpoint << std::endl;
        while(std::abs(this->processVariable - this->setpoint) > 0.001f )
        {
            this->processVariable += (std::abs(this->processVariable - this->setpoint))/2 ;
        }
        std::cout << "U's processVariable updated value: " << this->processVariable << std::endl;
        return this->processVariable * this->setpoint;
    }
};

struct Controller
{
    static float control(U& that, float& setpointTarget)
    {
        std::cout << "U's setpoint value: " << that.setpoint << std::endl;
        that.setpoint = setpointTarget;
        std::cout << "U's setpoint updated value: " << that.setpoint << std::endl;
        while(std::abs(that.processVariable - that.setpoint) > 0.001f )
        {
            that.processVariable += (std::abs(that.processVariable - that.setpoint))/2 ;
        }
        std::cout << "U's processVariable updated value: " << that.processVariable << std::endl;
        return that.processVariable * that.setpoint;
    }
};

int main()
{
    T person1(76, "Neil");
    T& person1Ref = person1;
    T person2(70, "Geddy");
    T& person2Ref = person2;

    std::cout << std::endl;
    MinHeight f;
    auto& smaller = f.compare(person1Ref, person2Ref);
    std::cout << "the smaller one is " << smaller.name << std::endl;

    std::cout << std::endl;
    U controlPoint1;
    U& controlPoint1Ref = controlPoint1;
    float updatedValue = 5.f;
    float& updatedValueRef = updatedValue;
    std::cout << "Controller::control controlPoint1's multiplied values:\n" << Controller::control(controlPoint1Ref, updatedValueRef) << std::endl;

    std::cout << std::endl;    
    U controlPoint2;
    std::cout << "controlMF controlPoint2's multiplied values:\n" << controlPoint2.controlMF(updatedValueRef) << std::endl;

    std::cout << std::endl;
}
