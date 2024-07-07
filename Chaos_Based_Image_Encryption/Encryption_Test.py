from PIL import Image

def npcr_uaci(original_image, encrypted_image):
    original = Image.open(original_image)
    encrypted = Image.open(encrypted_image)

    width, height = original.size
    total_pixels = width * height

    if original.size != encrypted.size:
        raise ValueError("Image sizes are different")

    npcr_count = 0
    uaci_sum = 0

    for x in range(width):
        for y in range(height):
            original_pixel = original.getpixel((x, y))
            encrypted_pixel = encrypted.getpixel((x, y))

            # Calculate NPCR
            if original_pixel != encrypted_pixel:
                npcr_count += 1

            # Calculate UACI
            uaci_sum += abs(original_pixel[0] - encrypted_pixel[0]) / 255
            uaci_sum += abs(original_pixel[1] - encrypted_pixel[1]) / 255
            uaci_sum += abs(original_pixel[2] - encrypted_pixel[2]) / 255

    npcr = (npcr_count / total_pixels) * 100
    uaci = (uaci_sum / (total_pixels *2.4)) * 100

    return npcr, uaci

original_image_path = r"2.jpg"
encrypted_image_path = r"D:\STUDIES\pythonProject\dhilip\Encrpyted.jpg"

npcr_value, uaci_value = npcr_uaci(original_image_path, encrypted_image_path)
print(f"NPCR: {npcr_value:.4f}%")
print(f"UACI: {uaci_value:.4f}%")
