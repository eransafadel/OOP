#include "ClassNames.h"

//----------------getName-------------------------------------------------------
const std::string& ClassNames::getName() const
{
	if (MIN_RANGE < m_index_name&&m_index_name < MAX_RANGE_CLASS)
		return m_class_names[m_index_name];
	return m_class_names[DEFAULT];//Defult=1

}
//------------------------------------------------------------------------------

