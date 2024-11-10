#include <string>
#include <iostream>
#include <vector>
#include <utility>

std::vector<std::string> createAndSendMessage();
void displaySentMessages(const std::vector<std::string>& messages);

int main() {
    std::vector<std::string> sentMessages = createAndSendMessage();
    displaySentMessages(sentMessages);
    return 0;
}

std::vector<std::string> createAndSendMessage() {
    std::vector<std::string> drafts;
    drafts.reserve(3);

    std::string draft;
    char choice;
    do {
        std::cout << "Enter your message draft: ";
        std::getline(std::cin, draft);
        // std::cin >> draft;

        if (!draft.empty()) {
            drafts.push_back(draft); 

            drafts.push_back(std::move(draft));
            draft.clear();
        } else {
            std::cout << "Draft cannot be empty. Please enter a valid message.\n";
        }

        std::cout << "Would you like to enter another draft? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return drafts;
}

void displaySentMessages(const std::vector<std::string>& messages) {
    std::cout << "\nSent Messages:\n";
    for (const auto& message : messages) {
        std::cout << message << '\n';
    }
}
