#include "Write.h"
#include <stb_image/stb_image_write.h>

namespace img {

void write_png(const char* file_path, const Image& image, bool flip_vertically)
{
    write_png(file_path, image.size.width(), image.size.height(), image.data.get(), flip_vertically);
}

void write_png(const char* file_path, ImageSize::DataType width, ImageSize::DataType height, void const* data, bool flip_vertically)
{
    stbi_flip_vertically_on_write(flip_vertically ? 1 : 0);
    stbi_write_png(file_path, static_cast<int>(width), static_cast<int>(height), 4, data, 0);
}

} // namespace img