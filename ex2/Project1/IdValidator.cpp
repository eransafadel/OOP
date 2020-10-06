#include "IdValidator.h"
#include "Macros.h"

//---------------------validatorTest---------------------------------------------
bool IdValidator::validatorTest(const std::uint32_t & val)
{
	std::string idNum = std::to_string(val);
	int sum = 0;

	if (idNum.size() != SIZE_OF_ID)		// id is length is incorrect
		return false;

	int incNum;				// sums the digit after multiply by 1 or 2
	for (int i = 0; i < 9; i++)
	{
		incNum = int(idNum[i] - '0') * ((i % 2) + 1);
		sum += (incNum > SIZE_OF_ID) ? incNum - SIZE_OF_ID : incNum;
	}

	return (sum % 10 == 0);

}
//-------------------------------------------------------------------------------
