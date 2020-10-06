#include "DestinationNames.h"

//---------------getName------------------------------------------------
const std::string& DestinationNames::getName() const
{
	if (MIN_RANGE < m_index_name&&m_index_name < MAX_RANGE_DEST)
		return m_DestinationNames[m_index_name];
	return m_DestinationNames[DEFAULT];//defult
}
//---------------------------------------------------------------------

