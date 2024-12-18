#include <map>
#include <cassert>
#include "generate_users.hpp"


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
    for (int i = 0; i < users.size(); ++i) {
        usersMap[users[i].email] = users[i];
    }
    return usersMap;
}

void printMap(map<string, User> aMap) {
    int i = 0;
    for (auto elem : aMap) {
        std::cout << "#" << i << ". Key: " << elem.first << ", Value: ";
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

bool testSearchByKey(map<string, User>& aMap, string keyToSearch) {
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
            std::cout << iter->second.userName << ": " << iter->second.numPosts << " tweets" << std::endl;
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
    std::cout << "The most popular category is " << mostPopularCategory << ", which is " << num << " users' most viewed category." << std::endl;
}



void testBuildMap(map<string, User>* mapByUserName, int numUsers) {
	std::cout << "Run test: build the map" << std::endl;
    if (mapByUserName == nullptr) {
        std::cout << "Error: Null pointer received." << std::endl;
        assert(false && "Null pointer received");
        return;
    }
    else {
        assert(mapByUserName->size() == static_cast<size_t>(numUsers));
        std::cout << "Test build the map passed" << std::endl;
        return;
    }
}



int main(int argc, char** argv)
{
	std::map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};

    int keyToCheck = 2;
	
    int numUsers = 10;
    vector<User> users = generateUsers(numUsers);


    std::cout << "Build map with username as key" << std::endl;
    map<string, User> mapByUserName = buildMapByUserName(users);
    std::cout << "Build map with email as key" << std::endl;
    map<string, User> mapByEmail = buildMapByEmail(users);

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <testName>" << std::endl;
        return 1;
    }

    std::string testName = argv[1];

    try {
        if (testName == "TestBuildMap") {
            testBuildMap(&mapByUserName, numUsers);
            testBuildMap(&mapByEmail, numUsers);
		}
		else if (testName == "TestPrintByUserName") {
			std::cout << "Print \"mapByUserName\" map:" << std::endl;
			printMap(mapByUserName);
			std::cout << std::endl;
		}
		else if (testName == "TestSearchByKey") {
		    std::cout << "Run test: Search by key" << std::endl;
			std::string keyToSearch = "smith55";
			assert(testSearchByKey(mapByUserName, keyToSearch));
			
			keyToSearch = "smitRick@gmail.com";
			assert(testSearchByKey(mapByEmail, keyToSearch));
			
			std::cout << "Test Search by key Passed" << std::endl;

		}
		else if (testName == "TestDeleteByKey") {
		    std::cout << "Run test: Delete by key" << std::endl;
			std::string keyToDelete = "lexi5";
		    assert(testDeleteByKey(mapByUserName, keyToDelete));

    		keyToDelete = "kat@gmail.com";
			assert(testDeleteByKey(mapByEmail, keyToDelete));
				
		    std::cout << "Test Delete by key Passed" << std::endl;
		}
		else if (testName == "TestSortedKey") {
			std::cout << "Run test if map's key is sorted" << std::endl;
		    assert(isMapSorted(mapByUserName) == 1);
		    std::cout << "Test Sorted Key Passed" << std::endl;

		}
		else if (testName == "TestPrintActiveUsers") {
		    std::cout << "Run test print usernames with more than 800 tweets:" << std::endl;
		    printActiveUsers(mapByUserName);
		    std::cout << std::endl;
			
		}
		else if (testName == "TestPrintMostPopularCategory") {
		    std::cout << "Run test print the most popular category" << std::endl;
		    printMostPopularCategory(mapByUserName);
		    std::cout << std::endl;
        } else {
            std::cerr << "Unknown test: " << testName << std::endl;
            return 1;
        }

        std::cout << "Test Passed: " << testName << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test Failed: " << testName << " - " << e.what() << std::endl;
        return 1;
    }


    return 0;
}
