//
//  main.cpp
//  Data Structure Vector
//
//  Created by Ziming on 7/29/18.
//  Copyright © 2018 Ziming. All rights reserved.
//

#include <iostream>
#include "MyVector.cpp"

int main(int argc, const char * argv[]) {
    
    //Test with size initialization
    myVector<int> mylist(4);
    
    //Test with array initialization
    double arr[] = {10.0, 0.0, 5.0, 6.0};
    double * p = arr;
    std::cout<<*p<<std::endl;
    p++;
    std::cout<<*p<<std::endl;
    std::cout<<"start testing constructor 2"<<std::endl;
    myVector<double> myVec1(arr,0,3);
    myVec1.printVector();
    
    //Test with vector initialization
    myVector<double> myVec2(myVec1,0,3);

    //Test expand function and insert function
    myVec2.insert(3, 1.0);
    myVec2.printVector();

    myVec2.insert(4,5.0);
    myVec2.insert(5,6.0);
    myVec2.insert(6,7.0);
    myVec2.printVector();
    
    
    //Test [] operator;
    std::cout<<myVec2[6]<<std::endl;
    
    
    //Test shrink and remove function
    std::cout<<"Test shrink and remove."<<std::endl<<"Orginal vector:"<<std::endl;
    myVec2.printVector();
    
    myVec2.remove(0, 5);
    myVec2.printVector();
    
    myVec2.remove(0);
    myVec2.printVector();

    //Test find function
    std::cout<<"Test find."<<std::endl;
    myVec2.insert(0,5.0);
    myVec2.insert(0,6.0);
    myVec2.insert(0,7.0);
    std::cout<<"Orginal vector:"<<std::endl;
    myVec2.printVector();
    int a = myVec2.find(5,0,3);
    std::cout<<a<<std::endl;
    
    //Test deduplicate
    std::cout<<"Test deduplicate."<<std::endl;
    myVec2.insert(0,5.0);
    myVec2.insert(0,5.0);
    myVec2.insert(0,5.0);
    myVec2.insert(0,6.0);
    myVec2.insert(0,7.0);
    myVec2.insert(0,6.0);
    
    myVec2.printVector();

    myVec2.deduplicate();
    myVec2.printVector();
    
    //Traverse
    std::cout<<"Test completed"<<std::endl;
    return 0;
}

