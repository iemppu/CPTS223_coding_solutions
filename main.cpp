#include <map>
#include <cassert>
#include "generate_users.hpp"

// TODO function 1
map<string, User> buildMapByUserName(const vector<User>& users) {
    map<string, User> usersMap;
    for (const auto& user : users)
    {
        usersMap[user.userName] = user;
    }
    return usersMap;
}

// TODO function 2
void testBuildMap(const map<string, User>* mapByUserName, int numUsers) {
	std::cout << "Run test: build the map" << std::endl;
    if (mapByUserName == nullptr) {
        assert(false && "Error: Null pointer received");
    }
    
	if (static_cast<int>(mapByUserName->size()) != numUsers) {
        assert(false && "Test build the map failed: map size mismatch");
	}
	std::cout << "Test build the map passed" << std::endl;
}

// TODO function 3
void printMap(map<string, User> aMap) {
    int i = 0;
    for (auto elem : aMap) {
        std::cout << "#" << i << ". Key: " << elem.first << ", Value: ";
        printAUser(elem.second);
        i++;
    }
}

// TODO function 4
void testSearchByKey(map<string, User>& aMap, string keyToSearch) {
	std::cout << "Run test: search by key" << std::endl;
    assert((aMap.find(keyToSearch) != aMap.end()) && "Key is not contained in the map");
	std::cout << "Test search by key Passed" << std::endl;
}

// TODO function 5
void testDeleteByKey(map<string, User> aMap, string keyToDelete) {		
	std::cout << "Run test: delete by key" << std::endl;
    assert((aMap.find(keyToDelete) != aMap.end()) && "Key is not contained in the map");
	std::cout << "Test delete by key Passed" << std::endl;
}

// TODO function 6
void testMapSorted(map<string, User> aMap) {
	std::cout << "Run test: if map's keys are sorted" << std::endl;
    if ( aMap.empty() == false ) {
	    map<string, User>::iterator iter = aMap.begin();
	    map<string, User>::iterator prev = iter;  
	    ++iter; 
	    while ( iter != aMap.end() ) {
	        if ( iter->first <= prev->first ) {
	            throw std::runtime_error("Test failed: Map keys are not sorted");
	        }
	        prev = iter; 
	        ++iter; 
	    }
	}
	std::cout << "Test sorted map key Passed" << std::endl;
}

// TODO function 7
void printActiveUsers(map<string, User> aMap) {
    int activeThreshold = 800;
    for ( auto iter = aMap.begin(); iter != aMap.end(); iter++) {
        if ( activeThreshold < iter->second.numPosts )
            std::cout << iter->second.userName << ": " << iter->second.numPosts << " tweets" << std::endl;
    }
}

// TODO function 8
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

// TODO function 9
map<string, User> buildMapByEmail(const vector<User>& users) {
    map<string, User> usersMap;
    for (const auto& user : users) {
        usersMap[user.email] = user;
    }
    return usersMap;
}

int main(int argc, char** argv)
{
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
			std::cout << std::endl;
		}
		else if (testName == "TestPrintByUserName") {
			std::cout << "Print \"mapByUserName\" map:" << std::endl;
			printMap(mapByUserName);
			std::cout << std::endl;
		}
		else if (testName == "TestSearchByKey") {
			std::string keyToSearch = "smith55";
			testSearchByKey(mapByUserName, keyToSearch);
			
			keyToSearch = "smitRick@gmail.com";
			testSearchByKey(mapByEmail, keyToSearch);
			std::cout << std::endl;
		}
		else if (testName == "TestDeleteByKey") {
			std::string keyToDelete = "lexi5";
		    testDeleteByKey(mapByUserName, keyToDelete);

    		keyToDelete = "kat@gmail.com";
			testDeleteByKey(mapByEmail, keyToDelete);
			std::cout << std::endl;
		}
		else if (testName == "TestSortedKey") {
		    testMapSorted(mapByUserName);
			std::cout << std::endl;
		}
		else if (testName == "TestPrintActiveUsers") {
		    std::cout << "Print usernames with more than 800 tweets:" << std::endl;
		    printActiveUsers(mapByUserName);
		    std::cout << std::endl;
		}
		else if (testName == "TestPrintMostPopularCategory") {
		    std::cout << "Print the most popular category" << std::endl;
		    printMostPopularCategory(mapByUserName);
		    std::cout << std::endl;
        } else {
            std::cerr << "Unknown test: " << testName << std::endl;
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "Test Failed: " << testName << " - " << e.what() << std::endl;
        return 1;
    }


    return 0;
}
