/*
    This file is part of Cute Chess.

    Cute Chess is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Cute Chess is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Cute Chess.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "genericmove.h"


GenericMove::GenericMove()
	: m_promotion(Chess::Piece::NoPiece)
{
}

GenericMove::GenericMove(const Chess::Square& sourceSquare,
			 const Chess::Square& targetSquare,
			 Chess::Piece::Type promotion)
	: m_sourceSquare(sourceSquare),
	  m_targetSquare(targetSquare),
	  m_promotion(promotion)
{
}

bool GenericMove::operator==(const GenericMove& other) const
{
	if (m_sourceSquare == other.m_sourceSquare
	&&  m_targetSquare == other.m_targetSquare
	&&  m_promotion == other.m_promotion)
		return true;
	return false;
}

bool GenericMove::operator!=(const GenericMove& other) const
{
	if (m_sourceSquare != other.m_sourceSquare
	||  m_targetSquare != other.m_targetSquare
	||  m_promotion != other.m_promotion)
		return true;
	return false;
}

bool GenericMove::isNull() const
{
	return !(m_sourceSquare.isValid() && m_targetSquare.isValid());
}

const Chess::Square& GenericMove::sourceSquare() const
{
	return m_sourceSquare;
}

const Chess::Square& GenericMove::targetSquare() const
{
	return m_targetSquare;
}

Chess::Piece::Type GenericMove::promotion() const
{
	return m_promotion;
}
