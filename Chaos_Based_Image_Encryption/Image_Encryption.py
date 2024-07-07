import numpy as np
from PIL import Image
# Specify the input file path with hex strings
input_file_path = 'hex_values.txt'

# Read the hex strings from the text file into an array
hex_strings = []
with open(input_file_path, 'r') as file:
    for line in file:
        hex_strings.append(line.strip())






s_box= [
    137, 140, 253, 68, 34, 133, 135, 175, 12, 35, 120, 119, 232, 74, 78, 233,
    41, 240, 31, 46, 69, 37, 127, 136, 79, 20, 184, 193, 207, 3, 24, 157,
    36, 221, 73, 236, 57, 167, 144, 77, 118, 215, 220, 226, 249, 108, 156,172,
    255, 45, 165, 201, 248, 49, 198, 163, 58, 80, 189, 30, 242, 94, 237, 254,
    17, 23, 114, 235, 247, 18, 152, 180, 15, 16, 44, 204, 100, 141, 224, 244,
    158, 109, 149, 208, 81, 199, 42, 166, 39, 28, 105, 32, 54, 103, 150, 21,
     0,65, 178, 25, 203, 125, 187, 251, 112, 123, 145, 174, 6, 89, 87, 90,
    138, 82, 111, 121, 241, 102, 104, 110, 47, 211, 106, 214, 86, 98, 117, 197,
    61, 107, 179, 92, 188, 128, 22, 75, 142, 146, 246, 195, 33, 93, 225, 9,
    76, 143, 162, 238, 181, 53, 116, 200, 229, 59, 52, 63, 239, 139, 177, 202,
    124, 194, 96, 132, 51, 161, 252, 155, 38, 192, 50, 29, 67, 1, 56, 97,
    147, 227, 115, 206, 148, 216, 62, 186, 40, 70, 171, 230, 2, 151, 48, 173,
    13, 223, 55, 130, 219, 72, 85, 185, 218, 183, 213, 14, 7, 83, 191, 228,
    153, 169, 4, 101, 205, 26, 126, 10, 160, 84, 182, 250, 210, 60, 5, 99,
    245, 11, 88, 209, 243, 64, 134, 190, 19, 131, 95, 234, 170, 212, 27, 66,
    159, 164, 231, 196, 43, 71, 176, 129, 217, 122, 91, 8, 222, 154, 168, 113
]







permutation_table = [20, 7, 36, 13, 23, 33, 3, 27, 17, 46, 9, 41, 44, 22, 12, 29, 18, 1, 32, 14,
                     26, 8, 4, 11, 38, 45, 19, 2, 30, 21, 47, 34, 5, 10, 15, 6, 25, 24, 31, 37, 0,
                     42, 43, 35, 40, 28, 16, 39]


input_file_path = 'key_strings.txt'

# Read the hex strings from the text file into an array
key_string = []
with open(input_file_path, 'r') as file:
    for line in file:
        key_string.append(line.strip())







Encrpyted_strings=[]

def substitute_bits(input_8bit, s_box):
    return s_box[input_8bit]



for data_string in hex_strings:
    if(len(data_string)!=96):
        print(data_string,len(data_string))

    original_384_bit = [int(data_string[i:i+2], 16) for i in range(0, len(data_string), 2)]

    for i in range(len(key_string)):
        key_str=key_string[i]

        key_bytes = [int(key_str[i:i+2], 16) for i in range(0, len(key_str), 2)]
       
        actual_value = sum(key_bytes) % 2
        
        if actual_value % 2 == 1:
            shifted_data_string = data_string[2:] + data_string[:2]
        else:
            shifted_data_string = data_string[-2:] + data_string[:-2]
            
        original_384_bit = [int(shifted_data_string[i:i+2], 16) for i in range(0, len(shifted_data_string), 2)]

        try:
            permuted_384_bit = [original_384_bit[index] for index in permutation_table]
        except IndexError:
            print(len(original_384_bit))
            print(original_384_bit)

        
        
        substituted_384_bit = [ substitute_bits(value, s_box) for value in permuted_384_bit]

        result = 0
        
        byte=''.join(format(x,'08b') for x in key_bytes)

        s_384_bit=''.join(format(x,'08b') for x in substituted_384_bit)

        result=""
        
        for i in range(len(byte)):
            if(byte[i]=="0" and s_384_bit[i]=="0" or byte[i]=="1" and s_384_bit[i]=="1"):
                result+="0"
            else:
                result+="1"

                        
        result_hex =''.join([hex(int(result[i:i+4],2))[2:].upper() for i in range(0,len(result),4)]) 
        data_string=result_hex
        
        
            
   
    Encrpyted_strings.append(result_hex)
       

# Specify the output file path
output_file_path = 'Encrpyted_strings.txt'

# Write the hex strings to a text file
with open(output_file_path, 'w') as file:
    for hex_string in Encrpyted_strings:
        file.write(hex_string + '\n')




print(f"Encrpyted_Hex_strings saved to '{output_file_path}'")




input_file_path = 'Encrpyted_strings.txt'

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

reconstructed_image.save(r"Encrpyted.jpg")




