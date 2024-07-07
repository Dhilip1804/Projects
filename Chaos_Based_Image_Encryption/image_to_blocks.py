from PIL import Image

# Open the color image

input_file_path = 'image_path.txt'

# Read the hex strings from the text file into an array
image_path =""
with open(input_file_path, 'r') as file:
    for line in file:
        image_path=line.strip()



image = Image.open(image_path)

# Convert the image to a NumPy array
image_data = image.load()

# Initialize an empty list to store the hexadecimal values
hex_values = []
hex_string = ""
count = 0

print(image.height,image.width)

# Iterate through each pixel and convert it to a hexadecimal value
for y in range(image.height):
    for x in range(image.width):
        pixel = image_data[x, y]
        hex_value = "{:02X}{:02X}{:02X}".format(pixel[0], pixel[1], pixel[2])
        hex_string += hex_value
        count += 1
        
        # If we have processed 16 pixels, add hex_string to hex_values and reset
        if count == 16:
            hex_values.append(hex_string)
            hex_string = ""
            count = 0

            
print(len(hex_values),count)



# If there are fewer than 16 pixels, add zero-padding
while count < 16:
    hex_string += "000000"
    count += 1
    # You can also break out of the loop if you want exactly 16 values,
    #even if there are fewer pixels available

# Append the last hex_string to hex_values
hex_values.append(hex_string)

print(hex_values[-1])

with open('hex_values.txt', 'w') as file:
    for hex_value in hex_values:
        if(len(hex_value)==96):
            file.write(hex_value + '\n')

print("Hex values saved to hex_values.txt")


