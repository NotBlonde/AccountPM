#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <openssl/evp.h>
#include <openssl/rand.h>
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

void showHackerBanner() {
    setTextColor("green");
    cout << R"(
     █████╗  ██████╗ ██████╗ ███████╗██████╗ 
    ██╔══██╗██╔════╝ ██╔══██╗██╔════╝██╔══██╗
    ███████║██║  ███╗██████╔╝█████╗  ██║  ██║
    ██╔══██║██║   ██║██╔═══╝ ██╔══╝  ██║  ██║
    ██║  ██║╚██████╔╝██║     ███████╗██████╔╝
    ╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚══════╝╚═════╝
    )" << endl;
    resetTextColor();
}

string generateSalt() {
    unsigned char salt[16];
    RAND_bytes(salt, sizeof(salt));
    stringstream ss;
    for (int i = 0; i < 16; i++) {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(salt[i]);
    }
    return ss.str();
}

string md5(const string& str) {
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;

    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, EVP_md5(), nullptr);
    EVP_DigestUpdate(ctx, str.c_str(), str.size());
    EVP_DigestFinal_ex(ctx, digest, &digest_len);
    EVP_MD_CTX_free(ctx);

    stringstream ss;
    for (unsigned int i = 0; i < digest_len; i++) {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(digest[i]);
    }
    return ss.str();
}

void accessGranted() {
    clearScreen();
    setTextColor("green");
    typewriterEffect("ACCESS GRANTED");
    resetTextColor();
}

void accessDenied() {
    clearScreen();
    setTextColor("red");
    typewriterEffect("ACCESS DENIED");
    resetTextColor();
}

int main(void) {
    clearScreen();
    showHackerBanner();
    typewriterEffect("Initializing system...");
    simulateLoading("Loading");
    
    while (true) {
        cout << "\nHACKER MENU:\n";
        cout << "1. Create User\n";
        cout << "2. Test Login\n";
        cout << "3. Exit\n";
        cout << "Enter command: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                typewriterEffect("Creating user...");
                string email, password;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;
                string salt = generateSalt();
                string hashedPassword = md5(password + salt);
                ofstream file("users.txt", ios::app);
                if (file.is_open()) {
                    file << email << ":" << salt << ":" << hashedPassword << endl;
                }
                simulateLoading("Encrypting credentials");
                break;
            }
            case 2: {
                typewriterEffect("Enter email: ");
                string email;
                cin >> email;
                typewriterEffect("Enter password: ");
                string password;
                cin >> password;
                simulateLoading("Verifying access");
                accessDenied();
                break;
            }
            case 3:
                simulateLoading("Shutting down");
                return 0;
            default:
                cout << "Invalid input, try again.\n";
                break;
        }
    }
}
