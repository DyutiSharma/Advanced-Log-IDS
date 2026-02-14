#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;


const int BRUTE_FORCE_THRESHOLD = 3;

string extractIP(const string& line) {
    size_t pos = line.find("IP:");
    if (pos != string::npos) {
        return line.substr(pos + 4);
    }
    return "";
}

int main() {

    cout << "=== Advanced Intrusion Detection System ===\n\n";

    ifstream file("logs.txt");
    if (!file) {
        cout << "Error: Could not open logs.txt\n";
        return 1;
    }

    string line;
    map<string, int> failedLoginCount;
    vector<string> alerts;

    while (getline(file, line)) {

    
        if (line.find("Failed password") != string::npos) {

            string ip = extractIP(line);

            if (!ip.empty()) {
            failedLoginCount[ip]++;
            }
        }

        
        if (line.find("Unauthorized access") != string::npos) {
            alerts.push_back("Unauthorized access detected!");
        }

        
        if (line.find("sudo rm") != string::npos) {
            alerts.push_back("Dangerous command usage detected!");
        }
    }

    file.close();

    
    for (auto& entry : failedLoginCount) {
        if (entry.second >= BRUTE_FORCE_THRESHOLD) {
 alerts.push_back("Brute force attack detected from IP: " + entry.first);
        }
    }

    
    if (alerts.empty()) {
    cout << "System Secure. No major threats detected.\n";
    } else {
        cout << "Threat Report:\n\n";
    for (const string& alert : alerts) {
         cout << "🚨 " << alert << endl;
        }
    }

    return 0;
}
