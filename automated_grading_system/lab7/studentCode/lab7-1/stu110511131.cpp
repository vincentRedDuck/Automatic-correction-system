#include <bits/stdc++.h>

using namespace std;

struct CARD{
  char suit;
  int value;
};

vector<int> spades(13,0);
vector<int> hearts(13,0);

int main() {
  char suit;
  int  value;
  for (int i = 0; i < 10; ++i) {
    printf ("#%d card suit: ", i + 1);
    cin >> suit;
    printf ("#%d card number: ", i + 1);
    cin >> value;
    if (suit == 's') {
      spades[value - 1] = value;
    }
    else if (suit == 'h') {
      hearts[value - 1] = value;
    }
  }
  printf ("\nafter sort\n");
  for (int i = 0; i < 13; ++i) {
    if (spades[i] != 0) {
      printf("suit: Spades number: %d\n", spades[i]);
    }
  }
  for (int i = 0; i < 13; ++i) {
    if (hearts[i] != 0) {
      printf("suit: Heart number: %d\n", hearts[i]);
    }
  }
}
