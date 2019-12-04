void TestSum()
{
	class Solution {
	public:
		int getSum(int a, int b) {
			int carry = a;
			int sum = b;
			do
			{
				int c = GetCarry(sum, carry);
				int s = GetSum(sum, carry);
				sum = s;
				carry = c;
			} while (carry != 0);

			return sum;
		}

	private:
		int GetCarry(int a, int b)
		{
			return (a&b) << 1;
		}

		int GetSum(int a, int b)
		{
			return (a^b);
		}
	};

	Solution s;
	std::cout << s.getSum(1, 2) << std::endl;
}