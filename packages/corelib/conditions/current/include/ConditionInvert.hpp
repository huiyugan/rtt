/***************************************************************************
  tag: Peter Soetens  Wed Jan 18 14:11:39 CET 2006  ConditionInvert.hpp 

                        ConditionInvert.hpp -  description
                           -------------------
    begin                : Wed January 18 2006
    copyright            : (C) 2006 Peter Soetens
    email                : peter.soetens@mech.kuleuven.be
 
 ***************************************************************************
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place,                                    *
 *   Suite 330, Boston, MA  02111-1307  USA                                *
 *                                                                         *
 ***************************************************************************/
 
 

#ifndef CONDITIONINVERT_HPP
#define CONDITIONINVERT_HPP

#include "ConditionInterface.hpp"

namespace ORO_CoreLib
{

    /**
     * A conditional that evaluates to the inverse of another Condition.
     */
    class ConditionInvert
        : public ConditionInterface
    {
        ConditionInterface* mc;
    public:
        ConditionInvert(ConditionInterface* c)
            : mc(c)
        {
        }

        virtual ~ConditionInvert()
        {
            delete mc;
        }

        virtual bool evaluate()
        {
            return ! mc->evaluate();
        }

        virtual ConditionInterface* copy( std::map<const DataSourceBase*, DataSourceBase*>& alreadyCloned ) const
        {
            return new ConditionInvert( mc->copy(alreadyCloned) );
        }

        virtual ConditionInterface* clone() const
        {
            return new ConditionInvert( mc->clone() );
        }
    };

}

#endif
