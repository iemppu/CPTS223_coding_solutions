/*
ADVANTAGES/DISADVANTAGES LINKED LIST

ADVANTAGES/DISADVANTAGES ARRAY
*/

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <tuple>
#include <random>
#include "linkedList.h"
#include "array.h"

using namespace std;

void populateCommands(string commandFilePath, LinkedList<string, string> *commandList) // Read CSV and input data into a linked list
{
    fstream fin;
    string line;
    fin.open(commandFilePath, ios::in);
    if (!fin.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }
    while (getline(fin, line))
    {
        string commandName, commandDescription;
        istringstream iss(line);
        getline(iss, commandName, ',');
        getline(iss, commandDescription);
        commandList->insertAtEnd(commandName, commandDescription);
    }
    fin.close(); 
}

void populateProfiles(string profileFilePath, LinkedList<string, int> *profileList) // Read CSV and input data into a linked list
{
    fstream fin;
    string line;
    fin.open(profileFilePath, ios::in);
    if (!fin.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }
    while (getline(fin, line))
    {
        string name, stringScore;
        istringstream iss(line);
        getline(iss, name, ',');
        getline(iss, stringScore);
        profileList->insertAtEnd(name, stoi(stringScore));
    }
    fin.close(); 
}

void populateProfiles(string profileFilePath, Array<string, int> *profileArray) // Read CSV and input data into a linked list
{
    fstream fin;
    string line;
    fin.open(profileFilePath, ios::in);
    if (!fin.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }
    while (getline(fin, line))
    {
        string name, stringScore;
        istringstream iss(line);
        getline(iss, name, ',');
        getline(iss, stringScore);
        profileArray->insertAtEnd(name, stoi(stringScore));
    }
    fin.close(); 
}

int main()
{
    string profileFilePath = "./profiles.csv";
    string commandFilePath = "./commands.csv";

    // LinkedList<string, int> profileList; // this is for linked list implementation for profiles
    Array<string, int> profileArray;
    populateProfiles(profileFilePath, &profileArray);

    LinkedList<string, string> commandList;
    populateCommands(commandFilePath, &commandList);

    string userName;
    int numQuestions;
    int selection;
    int questionIndex;
    // Node<string, int>* currentUser; // this is for linkedList implementation for profiles
    ArrayNode<string, int>* currentUserArray;
    Node<string, string>* randomNode1;
    Node<string, string>* randomNode2;
    Node<string, string>* randomNode3;
    string questionCommand;
    int correctCommand;
    int answerCommand;
    int totalScore;
    string newCommandToAdd;
    string newDescriptionToAdd;
    string oldCommandTodelete;
    string oldDescriptionToDelete;

    while (true)
    {
        cout << "Please select an option listed below:\n";
        cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n5. Remove Command\n6. Exit\n";
        cout << "Your selection: ";
        cin >> selection;     

        if (cin.fail()) // the input is not an integer
        {
            cout << "Your selection is invalid. Please select again." << endl;
            cout << "=============================================================================" << endl << endl;
            cin.clear();
            cin.ignore();
        }
        else
        {
            switch (selection)
            {
                case 1: // Game Rules
                {
                    cout << "================================= Game Rule ===================================" << endl;
                    cout << "To play the game, select \"2\" where you will be prompted for your name and number of questions.\n";
                    cout << "Each question presents a specific Linux command where you will be able to choose from 3 different options. Each correct answer yields a point.\n";
                    cout << "You can also add and delete commands as needed.\n";
                    cout << "================================= Game Rule ===================================" << endl << endl;

                    break;
                }

                case 2: case 3: // 2. Play Game; 3. Load Previous Game
                {
                    cout << "Please enter your name: ";
                    cin >> userName;

                    // attempt to find the userName from profiles
                    currentUserArray = profileArray.findNode(userName); // this is for linked list implementation for profiles
                    if (currentUserArray != NULL)
                    {    // existing userName
                        // currentUser->display();
                        totalScore = currentUserArray->value;
                        cout << "Welcome back, " << userName << "! Your latest total score is " << totalScore << endl;
                    }
                    else // new userName
                    {
                        totalScore = 0;
                        // profileList.insertAtEnd(userName, totalScore); // this is for linked list implementation for profiles
                        // currentUser = profileList.findNode(userName); // this is for linked list implementation for profiles
                        profileArray.insertAtEnd(userName, totalScore); // this is for Array implementation for profiles
                        currentUserArray = profileArray.findNode(userName); // this is for Array implementation for profiles
                        cout << "Welcome, " << userName << "! New profile has been created and your total score is 0!" << endl;
                    }
                    
                    while(true) // input a valid number of questions
                    {
                        cout << "Please select how many questions you would like to be asked (5-30): ";
                        cin >> numQuestions;

                        if (cin.good())
                        {
                            if (numQuestions >= 5)
                            {
                                break;
                            }
                            else{
                                cout << "Please give a valid number: " << endl;
                                cin.clear();
                                cin.ignore();
                            }
                        }
                        else
                        {
                            cout << "Please give a valid number: " << endl;
                            cin.clear();
                            cin.ignore();
                        }
                    }
                    cout << "=============================================================================" << endl;

                    for (int i = 0; i < numQuestions; i++)
                    {
                        // Node<string, string> *question = commandList.getRandom();
                        // cout << question->key << endl;
                        // cout << question->value << endl;

                        auto random3Nodes = commandList.getRandom3();

                        randomNode1 = get<0>(random3Nodes);
                        // randomNode1->display();

                        randomNode2 = get<1>(random3Nodes);
                        // randomNode2->display();

                        randomNode3 = get<2>(random3Nodes);
                        // randomNode3->display();

                        // randomly get a question command from the three
                        random_device rd;
                        mt19937 gen(rd());
                        uniform_int_distribution<> dis(1, 3);
                        questionIndex = dis(gen);
                        // cout << "questionIndex = " << questionIndex << endl;
                        switch (questionIndex)
                        {
                            case 1: // the first one will be used as the question command
                                questionCommand = randomNode1->key;
                                correctCommand = 1;
                                break;

                            case 2: // the second one will be used as the question command
                                questionCommand = randomNode2->key;
                                correctCommand = 2;
                                break;

                            case 3: // the third one will be used as the question command
                                questionCommand = randomNode3->key;
                                correctCommand = 3;
                                break;
                        }

                        cout << "Please pick the correct description for the command: " << questionCommand << endl;
                        cout << "1. " << randomNode1->value << endl;
                        cout << "2. " << randomNode2->value << endl;
                        cout << "3. " << randomNode3->value << endl;
                        cout << "Your answer: ";

                        cin >> answerCommand;
                        if (cin.fail())
                        {
                            cout << "Invalid answer. Please try again." << endl;
                            cin.clear();
                            cin.ignore();
                        }
                        else if (answerCommand == correctCommand)
                        {
                            totalScore++;
                            cout << "Correct!\nYou have been awarded 1 point.\n";
                            cout << "Your point total is " << totalScore << ".\n";
                            cout << "=============================================================================" << endl;
                        }
                        else
                        {
                            totalScore--;
                            cout << "Incorrect!\nYou have lost 1 point.\n";
                            cout << "Your point total is " << totalScore << ".\n";
                            cout << "=============================================================================" << endl;
                        }
                    } // end of for-loop for iterating all requested questions

                    currentUserArray->value = totalScore;
                    cout << userName << ": your total score is " << totalScore << " and has been successfully updated into our database." << endl;
                    cout << "=============================================================================" << endl;

                    break;
                }

                case 4: // Add Command
                {
                    cout << "To add a command to the library, please enter the command name that you would add: ";
                    cin >> newCommandToAdd;
                    if (commandList.findNode(newCommandToAdd) != NULL)
                    {
                        cout << newCommandToAdd << " has already been included in the library! Skip..." << endl;
                        cout << "=============================================================================" << endl << endl;
                        break;
                    }
                    else
                    {
                        cout << "Please enter the description that you would add: ";
                        cin.ignore(); // Ignore newline character from previous input
                        getline(cin, newDescriptionToAdd);
                        newDescriptionToAdd = "\"" + newDescriptionToAdd + "\"";
                        commandList.insertAtEnd(newCommandToAdd, newDescriptionToAdd);
                        cout << "A new command with description has been successfully added into the library!" << endl;
                        cout << "=============================================================================" << endl << endl;
                        // commandList.printList();
                        break;
                    }
                }

                case 5: // Remove Command
                {
                    cout << "Please enter the name of the command that you would remove: ";
                    cin >> oldCommandTodelete;
                    commandList.deleteNode(oldCommandTodelete);
                    // no need to output: this info will be printed out within "deleteNode()"
                    // commandList.printList();

                    cout << "=============================================================================" << endl << endl;

                    break;
                }
                    
                case 6: // Exit
                {
                    commandList.saveToFile(commandFilePath);
                    // profileList.saveToFile(profileFilePath);// this is for linkedList implementation for profiles
                    profileArray.saveToFile(profileFilePath);// this is for Array implementation for profiles

                    return 0;
                }

                case 7:
                {
                    cout << "This hidden option is for testing: print out all commands and profiles in the format of linked list: " << endl;
                    commandList.printList();
                    // profileList.printList(); // this is for linkedList implementation for profiles
                    profileArray.printArray();

                    break;
                }

            } // end of switch(selection)
        } // end of else: check (cin.fail())
        
    } // end of while(true)
} // end of int main()


