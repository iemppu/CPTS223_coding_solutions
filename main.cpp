#include <map>
#include <unordered_map>
#include <cassert>
#include "generate_users.hpp"
using namespace std;


map<string, User> buildMapByUserName(vector<User> users) {
    map<string, User> usersMap;
    for (int i = 0; i < users.size(); ++i)
    {
        usersMap[users[i].userName] = users[i];
    }
    return usersMap;
}


map<string, User> buildMapByEmail(vector<User> users) {
    map<string, User> usersMap;
    for (int i = 0; i < users.size(); ++i)
    {
        usersMap[users[i].email] = users[i];
    }
    return usersMap;
}

void printMap(map<string, User> aMap) {
    int i = 0;
    for (auto elem : aMap) {
        cout << "#" << i << ". Key: " << elem.first << ", Value: ";
        printAUser(elem.second);
        i++;
    }
}

bool isMapSorted(map<string, User> aMap) {
    if ( aMap.empty() )
        return true;

    map<string, User>::iterator iter = aMap.begin();
    map<string, User>::iterator prev = iter;  
    ++iter; 

    while ( iter != aMap.end() ) {
        if ( iter->first <= prev->first ) {
            return false;
        }
        prev = iter; 
        ++iter; 
    }
    return true;

}

bool testSearchByKey(map<string, User> aMap, string keyToSearch) {
    auto iter = aMap.find(keyToSearch);

    if (iter != aMap.end())
        return true; 
    else
        return false; 
}

bool testDeleteByKey(map<string, User> aMap, string keyToDelete) {
    auto iter = aMap.find(keyToDelete);

    if (iter == aMap.end()) 
        return false;
    else {
        aMap.erase(keyToDelete);
        iter = aMap.find(keyToDelete);
        if (iter == aMap.end())
            return true; 
        else
            return false; 
    }
}

void printActiveUsers(map<string, User> aMap) {
    int activeThreshold = 800;
    for ( auto iter = aMap.begin(); iter != aMap.end(); iter++) {
        if ( activeThreshold < iter->second.numPosts )
            cout << iter->second.userName << ": " << iter->second.numPosts << " tweets" << endl;
    }
}

void printMostPopularCategory(map<string, User> aMap) {
    map<string, int> categoryMap;
    for ( auto iter = aMap.begin(); iter != aMap.end(); iter++ ) {
        categoryMap[iter->second.mostViewedCategory]++;
    }
    string mostPopularCategory;
    int num;
    for ( auto iter = categoryMap.begin(); iter != categoryMap.end(); iter++ ) {
        if ( num < iter->second ) {
            num = iter->second;
            mostPopularCategory = iter->first;
        }
    }
    cout << "The most popular category is " << mostPopularCategory << ", which is " << num << " users' most viewed category." << endl;
}



void testBuildMap(map<string, User>* mapByUserName, int numUsers) {
    if (mapByUserName == nullptr) {
        cout << "Error: Null pointer received." << endl;
        assert(false && "Null pointer received");
        return;
    }
    else {
        assert(mapByUserName->size() == static_cast<size_t>(numUsers));
        cout << "Test build the map passed" << endl;
        return;
    }
}



int main()
{
    int numUsers = 10;
    vector<User> users = generateUsers(numUsers);


    cout << "Build map with username as key" << endl;
    map<string, User> mapByUserName = buildMapByUserName(users);

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <testName>" << std::endl;
        return 1;
    }

    std::string testName = argv[1];

    try {
        if (testName == "testBuildMap") {
            testBuildMap(&mapByUserName);
		}
		else if (testName == "PrintLevels") {
			testPrintLevels(bst);
		}
		else if (testName == "TestContain") {
			testContain(bst);
		}
		else if (testName == "TestSize") {
			testSize(bst);
		}
		else if (testName == "TestHeight") {
			testHeight(bst);
		}
		else if (testName == "PrintMaxPath") {
			testPrintMaxPath(bst);
		}
		else if (testName == "TestDelete") {
			testDelete(bst);
        } else {
            std::cerr << "Unknown test: " << testName << std::endl;
            return 1;
        }

        std::cout << "Test Passed: " << testName << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test Failed: " << testName << " - " << e.what() << std::endl;
        return 1;
    }
    

    cout << "Print \"mapByUserName\" map:" << endl;
    printMap(mapByUserName);
    cout << endl;


    string keyToSearch = "smith55";
    cout << "Search by key: mapByUserName[\"" << keyToSearch << "\"]" << endl;
    if ( testSearchByKey(mapByUserName, keyToSearch) )
        cout << "  Search successfully." << endl << endl;
    else
        cout << "  Search unsuccessfully." << endl << endl;


    string keyToDelete = "smith55";
    cout << "Delete by key: \"" << keyToDelete << "\"" << endl;
    if ( testDeleteByKey(mapByUserName, keyToDelete) )
        cout << "  Delete successfully." << endl << endl;
    else
        cout << "  Delete unsuccessfully." << endl << endl;


    cout << "Test if map's key is sorted" << endl;
    if ( isMapSorted(mapByUserName) )
        cout << "  Order test passed!" << endl << endl;
    else
        cout << "  Order test failed!" << endl << endl;


    cout << "Print usernames with more than 800 tweets:" << endl;
    printActiveUsers(mapByUserName);
    cout << endl;

    cout << "Print the most popular category" << endl;
    printMostPopularCategory(mapByUserName);
    cout << endl;


    cout << " ============================================================================== " << endl << endl;


    cout << "Build map with username as key" << endl;
    map<string, User> mapByEmail = buildMapByEmail(users);
    if ( mapByEmail.size() == numUsers )
        cout << "  Built successfully." << endl << endl;
    else
        cout << "  Built unsuccessfully." << endl << endl;
    

    keyToSearch = "kat@gmail.com";
    cout << "Search by key: mapByEmail[\"" << keyToSearch << "\"]" << endl;
    if ( testSearchByKey(mapByEmail, keyToSearch) )
        cout << "  Search successfully." << endl << endl;
    else
        cout << "  Search unsuccessfully." << endl << endl;


    keyToDelete = "kat@gmail.com";
    cout << "Delete by key: \"" << keyToDelete << "\"" << endl;
    if ( testDeleteByKey(mapByEmail, keyToDelete) )
        cout << "  Delete successfully." << endl << endl;
    else
        cout << "  Delete unsuccessfully." << endl << endl;


    return 0;
}
