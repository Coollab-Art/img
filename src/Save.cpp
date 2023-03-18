#include "Save.h"
#include <stb_image/stb_image_write.h>

namespace img {

void save_png(std::filesystem::path file_path const&, Image const& image, bool flip_vertically)
{
    save_png(file_path, image.width(), image.height(), image.data(), image.channels_count(), flip_vertically);
}

void save_png(
    std::filesystem::path const& file_path,
    Size::DataType               width,
    Size::DataType               height,
    const void*                  data,
    int                          channels_count,
    bool                         flip_vertically
)
{
    stbi_flip_vertically_on_write(flip_vertically ? 1 : 0);
    stbi_write_png(file_path.string().c_str(), static_cast<int>(width), static_cast<int>(height), channels_count, data, 0);
}

void save_jpeg(std::filesystem::path const& file_path, Image const& image, bool flip_vertically)
{
    save_jpeg(file_path.string().c_str(), image.width(), image.height(), image.data(), image.channels_count(), flip_vertically);
}

void save_jpeg(
    std::filesystem::path const& file_path,
    Size::DataType               width,
    Size::DataType               height,
    void const*                  data,
    int                          channels_count,
    bool                         flip_vertically
)
{
    stbi_flip_vertically_on_write(flip_vertically ? 1 : 0);
    stbi_write_jpg(file_path.string().c_str(), static_cast<int>(width), static_cast<int>(height), channels_count, data, 100);
}

} // namespace img