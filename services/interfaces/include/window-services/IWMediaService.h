/*
* File: IWMediaService.h
* Author: trung.la
* Date: 02-09-2025
* Description: This file contains the declaration of the IWMediaService class
*/

#ifndef IW_MEDIA_SERVICE_H_
#define IW_MEDIA_SERVICE_H_

#include <WindowServiceExport.h>
#include "../IService.h"

class WMEDIA_SERVICE_API IWMediaService : public IService
{
public:
    virtual ~IWMediaService() = default;

    virtual void start() = 0;
    virtual void getMediaInfo() = 0;
    virtual bool playAsync() = 0;
    virtual bool pauseAsync() = 0;
    virtual bool nextAsync() = 0;
    virtual bool previousAsync() = 0;
};

#endif // IW_MEDIA_SERVICE_H_
