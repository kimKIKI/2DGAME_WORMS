#pragma once
#include "cSingletonBase.h"
#include "cImage.h"

#define g_pImageManager cImageManager::GetInstance()

/*
자료구조 : map - 키 값과 데이터를 가지는 자료구조
*/

class cImageManager : public cSingletonBase<cImageManager>
{
private:
	map<string, cImage*>			m_mapImage;
	map<string, cImage*>::iterator	m_mapIter;

public:
	cImageManager();
	~cImageManager();

	//==================================================================
	//		## 셋업 ##
	//==================================================================
	// 빈 비트맵 셋업
	cImage* AddEmptyImage(string key, int width, int height);
	// 이미지 파일 셋업
	cImage* AddImage(string key, const char* fileName, int width, int height,
		bool isTrans = false, COLORREF transColor = RGB(0, 0, 0))
	{
		cImage* img = FindImage(key);

		if (img == NULL)
		{
			img = new cImage;
			img->SetupImage(fileName, width, height, isTrans, transColor);
			m_mapImage.insert(make_pair(key, img));
		}

		return img;
	}
	// 프레임 이미지 셋업
	cImage* AddFrameImage(string key, const char* fileName, int width, int height, int frameX, int frameY,
		bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	cImage* AddFrameImage(string key, const char* fileName, int width, int height, int frameX, int frameY,
		int x, int y, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));

	//==================================================================
	//		## 이미지 검색 및 삭제 ##
	//==================================================================
	cImage* FindImage(string key)
	{
		// 맵에서 키 값에 해당하는 자료를 찾아서 이터레이터에 넣는다.
		m_mapIter = m_mapImage.find(key);

		// 키 값에 해당하는 데이터가 있는 경우 데이터 값을 반환
		// first == 키 값, second == 데이터 값
		if (m_mapIter != m_mapImage.end())
			return m_mapIter->second;

		// 키 값에 해당하는 데이터가 없는 경우 널 반환
		return NULL;
	}		// 이미지 찾기
	void ReleaseImage(string key);		// 이미지 삭제

	//==================================================================
	//		## 일반 렌더 ##
	//==================================================================
	void Render(string key, HDC hdc);
	void Render(string key, HDC hdc, int destX, int destY);
	void Render(string key, HDC hdc, int destX, int destY, int sizeX, int sizeY);
	void Render(string key, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//==================================================================
	//		## 알파 렌더 ##
	//==================================================================
	void AlphaRender(string key, HDC hdc, int destX, int destY, BYTE alpha);

	//==================================================================
	//		## 프레임 렌더 ##
	//==================================================================
	void FrameRender(string key, HDC hdc, int destX, int destY);
	void FrameRender(string key, HDC hdc, int destX, int destY, int sourX, int sourY);
	void FrameRender(string key, HDC hdc, int destX, int destY, int sourX, int sourY, int sizeX, int sizeY);
	void FrameRender(string key, HDC hdc, int destX, int destY,
		int sourX, int sourY, int maxX, int maxY, int delay);
};

