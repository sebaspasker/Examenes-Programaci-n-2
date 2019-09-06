#include <iostream>

#include "Category.h"

using namespace std;

int main() {
Category c1("Famous", 70);
Category c2("Noobs", 30);
c1.addForbiddenNick("Rubius");
c1.addForbiddenNick("Auron");
c1.addForbiddenNick("Dulceida");
c1.addForbiddenNick("Adelita Power");
c1.addYoutuber("ExpCaseros", "http://www.youtube.com/channel/expcaseros");
c1.addYoutuber("Wismichu", "http://www.youtube.com/channel/wismichu");
c1.addYoutuber("PewDiePie", "http://www.youtube.com/channel/pewdiepie");
c1.addYoutuber("FakeRubius", "http://www.youtube.com/channel/fakerubius");
c1.penalize("PewDiePie");
c2.addYoutuber("Wannabe", "http://instagram.com/wannabe");
c2.addYoutuber("Adelaida", "http://www.youtube.com/channel/adelaida");
c1.penalize("PewDiePie");
c1.addYoutuber("PewDiePie2", "http://www.youtube.com/channel/pewdiepie2");
c1.shareProfits(12345.0);
c2.shareProfits(12345.0);
cout << c1;
cout << c2;
}