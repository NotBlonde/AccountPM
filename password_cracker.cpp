#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <openssl/evp.h>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

void clearScreen() {
    system("cls");
}

void setTextColor(const string& color) {
    if (color == "green") {
        cout << "\033[32m";
    } else if (color == "red") {
        cout << "\033[31m";
    } else if (color == "cyan") {
        cout << "\033[36m";
    }
}

void resetTextColor() {
    cout << "\033[0m";
}

void typewriterEffect(const string& text) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
}

void simulateLoading(const string& message) {
    cout << message;
    for (int i = 0; i < 3; ++i) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << ".";
        cout.flush();
    }
    cout << endl;
}

string hashPassword(const string& password, const string& algo) {
    const EVP_MD* md = nullptr;
    if (algo == "MD5") {
        md = EVP_md5();
    } else if (algo == "SHA256") {
        md = EVP_sha256();
    } else {
        cerr << "Unknown hashing algorithm!\n";
        exit(1);
    }
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;

    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, md, nullptr);
    EVP_DigestUpdate(ctx, password.c_str(), password.size());
    EVP_DigestFinal_ex(ctx, digest, &digest_len);
    EVP_MD_CTX_free(ctx);

    stringstream ss;
    for (unsigned int i = 0; i < digest_len; i++) {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(digest[i]);
    }
    return ss.str();
}

unordered_map<string, string> loadHashes() {
    unordered_map<string, string> hashTable;
    ifstream file("hashes.txt");
    string line, password, hash;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, password, ':');
        getline(ss, hash);
        hashTable[hash] = password;
    }
    return hashTable;
}

void crackPassword() {
    unordered_map<string, string> hashTable = loadHashes();
    string inputHash;
    cout << "Enter a hash to check: ";
    cin >> inputHash;
    
    simulateLoading("Checking database");
    
    if (hashTable.find(inputHash) != hashTable.end()) {
        setTextColor("green");
        cout << "Match found! Password: " << hashTable[inputHash] << endl;
    } else {
        setTextColor("red");
        cout << "No match found." << endl;
    }
    resetTextColor();
}

int main() {
    clearScreen();
    typewriterEffect("Initializing password cracker...");
    simulateLoading("Loading hash database");
    
    while (true) {
        cout << "\nHACKER MENU:\n";
        cout << "1. Crack Password\n";
        cout << "2. Exit\n";
        cout << "Enter command: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                crackPassword();
                break;
            case 2:
                simulateLoading("Shutting down");
                return 0;
            default:
                cout << "Invalid input, try again.\n";
                break;
        }
    }
}
