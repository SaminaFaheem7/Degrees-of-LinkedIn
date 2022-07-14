#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "DSVector.h"
#include "DSString.h"
#include "DSLinkedList.h"

TEST_CASE("DSVector of Integers", "[DSVec_Int]"){
    DSVector<int> empty_vector;
    DSVector<int> test_vector;
    test_vector.pushBack(10);
    test_vector.pushBack(20);

    SECTION("Testing Empty Vector") {
        REQUIRE(empty_vector.getSize() == 0);
        REQUIRE(test_vector.getSize() != 0);
    }

    SECTION("Testing 10 at first pos and 20 at second") {
        REQUIRE(test_vector[0] == 10);
        REQUIRE(test_vector[1] == 20);
    }

    SECTION("Testing that after pushing back a new element, it is in pos 3") {
        test_vector.pushBack(30);
        CHECK(test_vector[2] == 30);
    }
    SECTION("Push back 30 from above is not in test vector in new section") {
        REQUIRE(test_vector[1] == 20);
    }

    SECTION("Resize") {
        REQUIRE(test_vector.getSize() == 2);
        for (int i = 0; i < 5; i++) {
            test_vector.pushBack(3);
            test_vector.pushBack(22);
            test_vector.pushBack(11);
        }
        REQUIRE(test_vector.getSize() == 17);
    }

    SECTION("Pushback Vector of String")
    {
        DSVector<DSString> test_c;
        DSString c = "Testtt";
        test_c.pushBack(c);
        REQUIRE((test_c[0] == c) == 1);
    }

    SECTION("Operator="){
        DSVector<DSString> Testing;
        Testing.pushBack("case1");
        Testing.pushBack("case2");
        Testing.pushBack("case3");

        DSVector<DSString> test = Testing;

        REQUIRE((Testing[0]== test[0]));
        REQUIRE((Testing[2]== test[2]));
        REQUIRE(Testing[3]== test[3]);
   }

    SECTION("GetSize"){
        REQUIRE(test_vector.getSize()==2);
    }

    SECTION("Operator[]"){
        DSVector<int> test;
        test.pushBack(1);
        test.pushBack(2);
        test.pushBack(3);

        REQUIRE(test[0]==1);
        REQUIRE(test[1]==2);
        REQUIRE(test[2]==3);
    }

    SECTION("Remove Value"){
        DSVector<int> integers;
        for(int i=0; i < 5; i++)
        {
            integers.pushBack(2);
            integers.pushBack(11);
        }
        integers.remove_value(2);

        REQUIRE(integers.searchindex(2)==-1);
    }

    SECTION("Remove Index")
    {
        test_vector.remove_value(10);
        REQUIRE(test_vector[0]==20);
    }

    SECTION("Search Index")
    {
        DSVector<int> test;

        test.pushBack(12);
        test.pushBack(32);
        test.pushBack(33);

        REQUIRE(test.searchindex(12)==0);
        REQUIRE(test.searchindex(32)==1);
        REQUIRE(test.searchindex(33)==2);
        REQUIRE(test.searchindex(311)==-1);
    }

    SECTION("Sorting Function")
    {
        DSVector<int> number;
        number.pushBack(2);
        number.pushBack(12);
        number.pushBack(16);
        number.pushBack(5);
        number.pushBack(3);

        number.selectionsort();

        REQUIRE(number[0]==2);
        REQUIRE(number[1]==3);
        REQUIRE(number[2]==5);
        REQUIRE(number[3]==12);
        REQUIRE(number[4]==16);
    }
}

// Testing DSString
TEST_CASE("Testing DSStrings", "[DSVec_string]") {

    DSString test = "Samina";
    DSString test_case= "test";

    SECTION("Operator="){
        DSString Case1;
        test=Case1;
        REQUIRE(test==Case1);
    }

    SECTION("Testing operator+") {
        test = test+ " F";
        CHECK(test == "Samina F");
    }

    SECTION("Operator +="){
        DSString string="ing";
        test_case += string;
        CHECK(test_case == "testing");
    }

    SECTION("Operator =="){
        DSString string_testing="Samina";
        CHECK(string_testing == test);
    }

    SECTION("Operator>"){
        DSString test1="Sam";
        CHECK(test.operator>(test1));
    }

    SECTION("Operator<"){
        DSString test1="Sam";
        CHECK(test1.operator<(test));
    }

    SECTION("Operator<="){
        DSString test1="testing";
        DSString test2= "test";
        CHECK(test_case.operator<=(test1));
        CHECK(test_case.operator<=(test2));
    }

    SECTION("Operator >= "){
        DSString test1="testing";
        DSString test2= "test";
        CHECK(test1.operator>=(test_case));
        CHECK(test_case.operator>=(test2));

    }

    SECTION("Testing operator[]") {
        CHECK(test.operator[](1) == 'a');
    }

    SECTION("Testing length"){
        CHECK(test.getLength() == 6);
    }

    SECTION("Testing Sub String") {
        test = test.substring(1, 3);
        CHECK(test[0] == 'a');
    }

    SECTION("Lower Alphabets"){
        DSString test = "TeSTing";
        test.lower_alphabets();

        CHECK(test[0]=='t');
        CHECK(test[2]=='s');
        CHECK(test[1]!= 'E');
    }

    SECTION("Contains"){
        DSString test="Test something";
        CHECK(test.contains("i")==true);
        CHECK(test.contains("n")==true);
        CHECK(test.contains("f")==false);
   }
}

TEST_CASE("Testing DSLinkedList", "[DSVec_string]"){
    DSLinkedList<int> test;
    test.push_back(2);
    test.push_back(1);
    test.push_front(3);

    DSLinkedList<DSString> test_strings;
    test_strings.push_back("p");
    test_strings.push_back("l");
    test_strings.push_back("e");


    SECTION("operator="){
        DSLinkedList<int> testing;
        testing = test;
        CHECK (testing.at(0)==3);


        DSLinkedList<DSString> tests_strings;
        tests_strings = test_strings;
        CHECK(tests_strings.at(0)=="p");
    }

    SECTION("push back") {
        test.push_back(3);
        CHECK(test.get_size() == 4);

        test_strings.push_back("a");
        test_strings.push_back("s");
        test_strings.push_back("e");

        CHECK(test_strings.get_size() == 6 );
    }

    SECTION ("Push front"){
        test.push_front(3);
        test.push_front(4);

        CHECK(test.get_size()== 5);

        test_strings.push_front("o");
        CHECK(test_strings.at(0) == "o");
    }

    SECTION("At"){
        CHECK(test.at(1)==2);
        CHECK(test_strings.at(1)=="l");
    }

    SECTION("Print"){
        test.print();
        test_strings.print();
    }

    SECTION("Back Iterator"){
        test.back_iterator();
        CHECK(test.get_iterator()==1);

        test.push_back(7);
        test.back_iterator();
        CHECK(test.get_iterator()==7);
    }

    SECTION("Front Iterator"){
        test.front_iterator();
        CHECK(test.get_iterator() == 2);

        test.push_front(9);
        test.push_back(10);
        test.front_iterator();
        CHECK(test.get_iterator()== 3);
    }

    SECTION("Increment iterator" ){
        test.front_iterator();
        test.increment_iterator();
        //front points to next that's why it points to 1 instead of 2
        CHECK(test.get_iterator()==1);
    }

    SECTION("is it front"){
        test.front_iterator();
        CHECK(test.is_front() == true);
    }

    SECTION("is in the back"){
        test.back_iterator();
        CHECK(test.is_back()== true);
    }


    SECTION("Clear"){
        test.clear();
        CHECK(test.get_size() == 0);

        test_strings.clear();
        CHECK(test_strings.get_size() == 0);
    }

    SECTION("Get Size"){
        CHECK(test.get_size()== 3);
        CHECK(test_strings.get_size() == 3);
    }

    SECTION("Insert"){
        test.insert(4,2);
        CHECK(test.at(2)==4);

        test_strings.insert("a", 2);
        CHECK(test_strings.at(2)=="a");
    }
}
