#include "Image.h"
#include <stb_image/stb_image.h>
#include <stdexcept>

namespace img {

Image::Image(const char* file_path, int channels_count, bool flip_vertically)
    : channels_count{channels_count}
{
    stbi_set_flip_vertically_on_load(flip_vertically ? 1 : 0);
    int w, h; // NOLINT
    data.reset(stbi_load(file_path, &w, &h, nullptr, channels_count));
    if (!data || w < 1 || h < 1) {
        throw std::runtime_error{"[img::read] Couldn't load image from \"" + std::string{file_path} + "\":\n" + stbi_failure_reason()};
    }
    else {
        size.set_width(static_cast<ImageSize::DataType>(w));
        size.set_height(static_cast<ImageSize::DataType>(h));
    }
}

} // namespace img