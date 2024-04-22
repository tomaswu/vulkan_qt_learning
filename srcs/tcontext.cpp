#include "tcontext.hpp"

namespace tw
{
    std::unique_ptr<TContext> TContext::singleton=nullptr;

    void TContext::Init()
    {
        if (!singleton)
        {
            singleton.reset(new TContext);
        }
    }
    void TContext::Quit()
    {
        singleton.reset();
    }

    TContext& TContext::getTContext()
    {
        if (!singleton)
        {
            singleton.reset(new TContext);
        }
        return *singleton;
    }

    TContext::TContext()
    {
        vk::InstanceCreateInfo info;
        vk::ApplicationInfo appinfo;
        auto avaiableLayers = vk::enumerateInstanceLayerProperties();
        auto avaiableExtensions = vk::enumerateInstanceExtensionProperties();
        for(auto &layer:avaiableLayers){
            std::cout<<layer.layerName<<std::endl;
        }

        appinfo.setApiVersion(VK_API_VERSION_1_3);
        instance = vk::createInstance(info);
        
    }

    TContext::~TContext()
    {
        instance.destroy();
    }

} // namespace tw
