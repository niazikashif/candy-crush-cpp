#include "Player.h"

Player::Player()
{
	p_Name = "";
	p_Score = 0;
	p_Level = 0;
	P_LevelTime = 0;
	p_Lives = 0;
}

Player::Player(string p_Name, int p_Score, int p_Level, int P_LevelTime)
{
	this->p_Name = p_Name;
	this->p_Score = p_Score;
	this->p_Level = p_Level;
	this->P_LevelTime = P_LevelTime;
	this->p_Lives = p_Lives;
}

void Player::setpName(string pname)
{
	p_Name = pname;
}

void Player::setpName(char pname)
{
	if (pname == 8 && p_Name.size() != 0)
		p_Name.pop_back();
	else if (pname != '\0' && p_Name.size() != 20)
		p_Name.push_back(pname);
}

std::string Player::getpName() const
{
	return p_Name;
}

void Player::setpScore(int ps)
{
	p_Score = ps;
}

int Player::getpScore() const
{
	return p_Score;
}

void Player::setpLevel(int pl)
{
	p_Level = pl;
}

int Player::getpLevel() const
{
	return p_Level;
}

void Player::setpLevelTime(int pt)
{
	P_LevelTime = pt;
}

int Player::getpLevelTime() const
{
	return P_LevelTime;
}

void Player::setpLives(int plives)
{
	p_Lives = plives;
}

int Player::getpLives() const
{
	return p_Lives;
}

void Player::DisplaypName() const
{
	/////////////////////////////////////////////////////////////
	////////////// PLAYER NAME //////////////
	DrawString(40, 620, "Player :", colors[WHITE]);
	DrawString(120, 620, getpName(), colors[WHITE]);
}

Player::~Player()
{
}