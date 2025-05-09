#include <InstrumentImpl.h>
#include <string>
#include <SYSTEMErr.h>

InstrumentImpl::InstrumentImpl(const ACE_CString& name, maci::ContainerServices * containerServices) : ACSComponentImpl(name, containerServices) {
}
 
InstrumentImpl::~InstrumentImpl() {
}
 
void InstrumentImpl::cameraOn() {
    std::string const mth = "InstrumentImpl::cameraOn";
    std::string const msg = mth + " called";
    std::cout << msg << std::endl;
    ACS_DEBUG(mth, msg);
    
    isCameraOn = true;
}

void InstrumentImpl::cameraOff() {
    std::string const mth = "InstrumentImpl::cameraOff";
    std::string const msg = mth + " called";
    std::cout << msg << std::endl;
    ACS_DEBUG(mth, msg);
 
    isCameraOn = false;
}

TYPES::ImageType * InstrumentImpl::takeImage(CORBA::Long exposureTime) {
    std::string const mth = "InstrumentImpl::takeImage";
    std::string const msg = mth + " called";
    std::cout << msg << std::endl;
    ACS_DEBUG(mth, msg);
    
    if(isCameraOn) {
	// Do nothing.
    }
    else {
    	throw SYSTEMErr::CameraIsOffExImpl(__FILE__, __LINE__, "InstrumentImpl::takeImage").getCameraIsOffEx();
    }

    return {};
}

void InstrumentImpl::setRGB(TYPES::RGB const & rgbConfig) {
    std::string const mth = "InstrumentImpl::setRGB";
    std::string const msg = mth + " called";
    std::cout << msg << std::endl;
    ACS_DEBUG(mth, msg);
}

void InstrumentImpl::setPixelBias(CORBA::Long bias) {
    std::string const mth = "InstrumentImpl::setPixelBias";
    std::string const msg = mth + " called";
    std::cout << msg << std::endl;
    ACS_DEBUG(mth, msg);
}

void InstrumentImpl::setResetLevel(CORBA::Long resetLevel) {
    std::string const mth = "InstrumentImpl::setResetLevel";
    std::string const msg = mth + " called";
    std::cout << msg << std::endl;
    ACS_DEBUG(mth, msg);
}

/* --------------- [ MACI DLL support functions ] -----------------*/
#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(InstrumentImpl)
/* ----------------------------------------------------------------*/
