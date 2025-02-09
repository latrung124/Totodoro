/*
* File: WindowMediaService.h
* Author: trung.la
* Date: 02-07-2025
* Description: This file contains the declaration of the WindowMediaService class
*/

#ifndef WINDOW_MEDIA_SERVICE_H
#define WINDOW_MEDIA_SERVICE_H

#include "window-services/IWMediaService.h"

class WMEDIA_SERVICE_API WindowMediaService : public IWMediaService
{
public:
    WindowMediaService();
    ~WindowMediaService() override;

    void start() override;
    void getMediaInfo() override;
};

#endif // WINDOW_MEDIA_SERVICE_H