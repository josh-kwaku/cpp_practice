#include <iostream>

using namespace std;

int letter_exists(char, char[], int);
void print_array(char[], int);
int main() {

    // Write your code here
    const int size = 6;
    char word[size] = { 's','p','i','r','i','t' };
    char answer[size];
    int no_of_guesses = 10;
    int count = 0;
    while (no_of_guesses != 0) {
        char letter[1];
        cout << "Guess: ";
        cin >> letter;
        int index = letter_exists(letter[0], word, size);
        if (index == -1)
            no_of_guesses--;
        else {
            answer[index] = letter[0];
            count++;
        }



        if (count == size) {
            cout << "Hurray!!! you win" << endl;
            cout << "Here's the word: ";
            print_array(answer, size);
            break;
        }
    }

    if (count != size) {
        cout << "Loser! Here's what you guessed: ";
        print_array(answer, size);
        cout << "Here's the word: ";
        print_array(word, size);
    }


}

int letter_exists(char letter, char arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == letter)
            return i;
    }
    return -1;
}

void print_array(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}