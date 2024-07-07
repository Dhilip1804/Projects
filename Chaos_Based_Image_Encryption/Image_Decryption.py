import numpy as np
from PIL import Image

# Specify the input file path with hex strings




input_file_path = 'Encrpyted_strings.txt'

# Read the hex strings from the text file into an array
Encrpyted_strings = []
with open(input_file_path, 'r') as file:
    for line in file:
        Encrpyted_strings.append(line.strip())






permutation_table = [20, 7, 36, 13, 23, 33, 3, 27, 17, 46, 9, 41, 44, 22, 12, 29, 18, 1, 32, 14,
                     26, 8, 4, 11, 38, 45, 19, 2, 30, 21, 47, 34, 5, 10, 15, 6, 25, 24, 31, 37, 0,
                     42, 43, 35, 40, 28, 16, 39]



input_file_path = 'key_strings.txt'

# Read the hex strings from the text file into an array
key_string = []
with open(input_file_path, 'r') as file:
    for line in file:
        key_string.append(line.strip())






inverse_s_box = [
    173, 188, 29, 210, 222, 108, 204, 251, 143, 215, 225, 8, 192, 203, 72, 73,
    64, 69, 232, 25, 95, 134, 65, 30, 99, 213, 238, 89, 171, 59, 18, 91,
    140, 4, 9, 32, 21, 168, 88, 184, 16, 86, 244, 74, 49, 19, 120, 190,
    53, 170, 164, 154, 149, 92, 194, 174, 36, 56, 153, 221, 128, 182, 155, 229,
    97, 239, 172, 3, 20, 185, 245, 197, 34, 13, 135, 144, 39, 14, 24, 57,
    84, 113, 205, 217, 198, 124, 110, 226, 109, 111, 250, 131, 141, 61, 234, 162,
    175, 125, 223, 76, 211, 117, 93, 118, 90, 122, 129, 45, 81, 119, 114, 104,
    255, 66, 178, 150, 126, 40, 11, 10, 115, 249, 105, 160, 101, 214, 22, 133,
    247, 195, 233, 163, 5, 230, 6, 23, 0, 112, 157, 1, 77, 136, 145, 38,
    106, 137, 176, 180, 82, 94, 189, 70, 208, 253, 167, 46, 31, 80, 240, 216,
    165, 146, 55, 241, 50, 87, 37, 254, 209, 236, 186, 47, 191, 107, 7, 246,
    158, 98, 130, 71, 148, 218, 201, 26, 199, 183, 102, 132, 58, 231, 206, 169,
    27, 161, 139, 243, 127, 54, 85, 151, 51, 159, 100, 75, 212, 179, 28, 83,
    227, 220, 121, 237, 202, 123, 41, 181, 248, 200, 196, 42, 33, 252, 193, 78,
    142, 43, 177, 207, 152, 187, 242, 12, 15, 235, 67, 35, 62, 147, 156, 17,
    116, 60, 228, 79, 224, 138, 68, 52, 44, 219, 103, 166, 2, 63, 48, 96
]



inverse_permutation_table = [0] * len(permutation_table)

for index, value in enumerate(permutation_table):
    inverse_permutation_table[value] = index




def inverse_substitute_bits(output_8bit, inverse_s_box):
    return inverse_s_box[output_8bit-1]

# Convert the encrypted result_hex back to a list of bytes


Decrpyted_strings=[]



for data_string in Encrpyted_strings:

    for i in range(len(key_string)-1,-1,-1):
        
       
        try:
             encrypted_bytes = bytes.fromhex(data_string)
        except ValueError:
            pass

        # Step 1: Undo the XOR operation with the key
        decrypted_substituted_384_bit = []

        key_bytes = bytes.fromhex(key_string[i])
        actual_value = sum(key_bytes) % 2
        for i, byte in enumerate(key_bytes):
            xor_value = byte ^ encrypted_bytes[i]
            decrypted_substituted_384_bit.append(xor_value)

            
        # Step 2: Undo the inverse S-box substitution
        decrypted_original_384_bit = [
            inverse_substitute_bits(value, inverse_s_box) for value in decrypted_substituted_384_bit]

        decrypted_original_384_bit = [decrypted_original_384_bit[index] for index in inverse_permutation_table]
        
        # Step 3: Undo the shifting
        if actual_value % 2 == 1:
            decrypted_original_384_bit = decrypted_original_384_bit[-1:] + decrypted_original_384_bit[:-1]
        else:
            decrypted_original_384_bit = decrypted_original_384_bit[1:] + decrypted_original_384_bit[:1]

      
        # Convert the decrypted values back to a hexadecimal string
        decrypted_data_string = ''.join(format(byte, '02X') for byte in decrypted_original_384_bit)
        data_string=decrypted_data_string
        
  
    Decrpyted_strings.append(decrypted_data_string)



# Specify the output file path
output_file_path = 'Decrpyted_strings.txt'

# Write the hex strings to a text file
with open(output_file_path, 'w') as file:
    for hex_string in Decrpyted_strings:
        file.write(hex_string + '\n')




print(f"Decrpyted_Hex_strings saved to '{output_file_path}'")



input_file_path = 'Decrpyted_strings.txt'

# Read the hex strings from the text file into an array
hex_values = []
with open(input_file_path, 'r') as file:
    for line in file:
        hex_values.append(line.strip())


input_file_path = 'image_path.txt'

# Read the hex strings from the text file into an array
image_path =""
with open(input_file_path, 'r') as file:
    for line in file:
        image_path=line.strip()





# Replace this with the path to your original image
original_image_path = image_path

# Open the original color image
original_image = Image.open(original_image_path)

# Define the width and height of the original image
original_width, original_height = original_image.size

# Initialize an empty list to store the hexadecimal values

hex_string = ""
# Create a new image using the dimensions of the original image
reconstructed_image = Image.new('RGB', (original_width, original_height))

# Iterate through the hexadecimal values and reconstruct the image
pixel_data = []
pixel_count = 0

for hex_string in hex_values:
    for i in range(0, len(hex_string), 6):  # Read six characters at a time
        if pixel_count < original_width * original_height:
            hex_color = hex_string[i:i+6]
            r = int(hex_color[0:2], 16)
            g = int(hex_color[2:4], 16)
            b = int(hex_color[4:6], 16)
            pixel_data.append((r, g, b))
            pixel_count += 1

# Put the pixel data into the reconstructed image
reconstructed_image.putdata(pixel_data)

# Display the reconstructed image
reconstructed_image.show()

reconstructed_image.save(r"Decrpyted.jpg")











