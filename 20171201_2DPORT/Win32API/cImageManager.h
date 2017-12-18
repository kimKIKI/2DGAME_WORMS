#pragma once
#include "cSingletonBase.h"
#include "cImage.h"

#define g_pImageManager cImageManager::GetInstance()

/*
�ڷᱸ�� : map - Ű ���� �����͸� ������ �ڷᱸ��
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
	//		## �¾� ##
	//==================================================================
	// �� ��Ʈ�� �¾�
	cImage* AddEmptyImage(string key, int width, int height);
	// �̹��� ���� �¾�
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
	// ������ �̹��� �¾�
	cImage* AddFrameImage(string key, const char* fileName, int width, int height, int frameX, int frameY,
		bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));
	cImage* AddFrameImage(string key, const char* fileName, int width, int height, int frameX, int frameY,
		int x, int y, bool isTrans = false, COLORREF transColor = RGB(0, 0, 0));

	//==================================================================
	//		## �̹��� �˻� �� ���� ##
	//==================================================================
	cImage* FindImage(string key)
	{
		// �ʿ��� Ű ���� �ش��ϴ� �ڷḦ ã�Ƽ� ���ͷ����Ϳ� �ִ´�.
		m_mapIter = m_mapImage.find(key);

		// Ű ���� �ش��ϴ� �����Ͱ� �ִ� ��� ������ ���� ��ȯ
		// first == Ű ��, second == ������ ��
		if (m_mapIter != m_mapImage.end())
			return m_mapIter->second;

		// Ű ���� �ش��ϴ� �����Ͱ� ���� ��� �� ��ȯ
		return NULL;
	}		// �̹��� ã��
	void ReleaseImage(string key);		// �̹��� ����

	//==================================================================
	//		## �Ϲ� ���� ##
	//==================================================================
	void Render(string key, HDC hdc);
	void Render(string key, HDC hdc, int destX, int destY);
	void Render(string key, HDC hdc, int destX, int destY, int sizeX, int sizeY);
	void Render(string key, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//==================================================================
	//		## ���� ���� ##
	//==================================================================
	void AlphaRender(string key, HDC hdc, int destX, int destY, BYTE alpha);

	//==================================================================
	//		## ������ ���� ##
	//==================================================================
	void FrameRender(string key, HDC hdc, int destX, int destY);
	void FrameRender(string key, HDC hdc, int destX, int destY, int sourX, int sourY);
	void FrameRender(string key, HDC hdc, int destX, int destY, int sourX, int sourY, int sizeX, int sizeY);
	void FrameRender(string key, HDC hdc, int destX, int destY,
		int sourX, int sourY, int maxX, int maxY, int delay);
};
