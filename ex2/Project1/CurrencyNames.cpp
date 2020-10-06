#include "CurrencyNames.h"

//------------------getName---------------------------------------------------
const std::string& CurrencyNames::getName() const
{
	if(MIN_RANGE < m_index_name && m_index_name < MAX_RANGE_CURRENCY)
		return m_currency_names[m_index_name];
	return m_currency_names[DEFAULT];//Defult
}
//----------------------------------------------------------------------------

