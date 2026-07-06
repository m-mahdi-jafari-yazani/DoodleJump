#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <stdexcept>

template<typename Resource>
class ResourceCache
{
public:
    const Resource& get(const std::string& filePath);

private:
    std::unordered_map<
        std::string,
        std::unique_ptr<Resource>
    > resources;
};

template<typename Resource>
const Resource&
ResourceCache<Resource>::get(
    const std::string& filePath
)
{
    auto it = resources.find(filePath);

    if (it != resources.end())
    {
        return *it->second;
    }

    auto resource =
        std::make_unique<Resource>();

    if (!resource->loadFromFile(filePath))
    {
        throw std::runtime_error(
            "Cannot load resource: " +
            filePath
        );
    }

    const Resource& reference =
        *resource;

    resources[filePath] =
        std::move(resource);

    return reference;
}
