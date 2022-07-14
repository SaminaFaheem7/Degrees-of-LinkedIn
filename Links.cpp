// Created by Samina Faheem on 6/15/2022.

#include "Links.h"
#include <fstream>
#include<stack>
using namespace std;

//Constructor
Links::Links(DSString filename, DSString output){
    readfile(filename);
    Outputfile(output);
}

//Reading in the file
void Links::readfile(DSString arg){
    ifstream file;
    file.open(arg.c_str());
    char* buffer = new char[1000];

    if(!file.is_open()){
        cout<< "Failed to open list.txt";
        exit(1);
    }

    file.getline(buffer ,1000);
    //Converting the buffer to integers for comparison
    int number_of_names= atoi (buffer);

    for(int i = 0; i < number_of_names; i++){
        file.getline(buffer, 1000, '|');
        DSString left_name;
        left_name = buffer;
        //Keeping the left name and removing the space
        left_name = left_name.substring(0,left_name.getLength()-1);

        file.getline(buffer , 1000);
        DSString right_name;
        right_name = buffer;
        //reading it after the space, so we disregard the space after the '|'
        right_name= right_name.substring(1, right_name.getLength());

        // Adding it to the connections both ways
        lists.add_connections(left_name, right_name);
        lists.add_connections(right_name, left_name);
    }
    //Getting the names where we need to explore the path to
    file.getline(buffer, 1000);
    int number_of_path = atoi (buffer);
    for(int i =0; i < number_of_path; i++){
        file.getline(buffer, 1000, '|');
        DSString left_name;
        left_name = buffer;
        left_name = left_name.substring(0,left_name.getLength()-1);

        file.getline(buffer , 1000);
        DSString right_name;
        right_name = buffer;
        right_name= right_name.substring(1, right_name.getLength());

        Paths names;
        names.starting_name = left_name;
        names.ending_name = right_name;
        paths.pushBack(names);
        iterative_backtracking(left_name, right_name);
    }
}

void Links:: iterative_backtracking(DSString start, DSString end){
    lists.reset_iterators();
    stack<DSString> path;
    DSLinkedList<DSLinkedList<DSString>> best_paths;

    path.push(start);
    //looping until the stack is not empty
    while(!path.empty()){
        //If the stack reaches till the last name
        if(path.top() == end) {
           // If the path is 0 or the size is less than the best path
            if (best_paths.get_size() == 0 || path.size() < best_paths.at(0).get_size()) {
                stack<DSString> curr = path;
                best_paths.clear();

                DSLinkedList<DSString> current_path;
                // While that current path aka shorter path is not empty
                while (!curr.empty()) {
                    current_path.push_front(curr.top());
                    curr.pop();
                }
                // We push the path we got to the best path and pop the rest
                best_paths.push_back(current_path);
                path.pop();
            }
            //if both the path sizes are same
            else if(path.size() == best_paths.get_size()){
                stack<DSString> curr = path;
                DSLinkedList<DSString> current_path;

                while (!curr.empty()) {
                    current_path.push_front(curr.top());
                    curr.pop();
                }
                best_paths.push_back(current_path);
                path.pop();
            }
        }
        // If the stack is null then add
        if(lists[path.top()].isnull()){
            lists[path.top()].front_iterator();
            path.pop();
        }
        else{
            DSString curr = lists[path.top()].get_iterator();

            // If the name is not on the stack then add
            if( lists[curr].is_front()){
                lists[path.top()].increment_iterator();
                path.push(curr);
            }
            else{
                lists[path.top()].increment_iterator();
            }

        }
    }
    results.push_back(best_paths);
}

//Output file
void Links:: Outputfile(DSString output){
    ofstream file;
    file.open(output.c_str());
    //Iterating over the path
    for(int i =0; i < paths.getSize(); i++) {
        file << paths[i].starting_name << "  | " << paths[i].ending_name << ":" << endl;
        //Getting the results
        for (int j = 0; j < results.at(i).get_size(); j++) {
           file << results.at(i).at(j).at(0);
           //Getting the exact name
           for (int k = 1; k < results.at(i).at(j).get_size(); k++) {
               file<< ">" << results.at(i).at(j).at(k);
            }
            file<<endl;
        }
    }
    file.close();
}