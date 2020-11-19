#include <iostream>


char RainbowAsChar[]={'R','O','Y','G','B','I','P'};
namespace Rainbow{
	using std::cin;
	using std::cout;
class RainbowColor{
	public:
		RainbowColor(int co);
		RainbowColor(char co);
		RainbowColor();
		int getRainbowColorByName(char name);
		int getRainbowColorByInt(int no);
		void outputRainbowColorInt();
		void outputRainbowColorChar();
		class RainbowColor getNextRainbowColor();
	private:
		int color;
};
}