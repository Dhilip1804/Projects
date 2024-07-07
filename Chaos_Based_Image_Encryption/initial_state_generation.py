import hashlib

def image_to_sha256_bytes(image_file_path):
    try:
        # Open the image file in binary mode
        with open(image_file_path, 'rb') as file:
            # Read the image content
            image_data = file.read()
            # Create a SHA-256 hash object
            sha256_hash = hashlib.sha256()
            # Update the hash object with the image data
            sha256_hash.update(image_data)
            # Get the binary representation of the hash
            hash_bytes = sha256_hash.digest()
            return list(hash_bytes)
    except FileNotFoundError:
        return None

def normalized_value(x):
    final=0
    for i in x:
        final^=i

    return final/2**8
        


input_file_path = 'image_path.txt'

# Read the hex strings from the text file into an array
image_path =""
with open(input_file_path, 'r') as file:
    for line in file:
        image_path=line.strip()




# Provide the path to your image file
byte_list = image_to_sha256_bytes(image_path)

print(byte_list)

a=byte_list[0:11]
b=byte_list[11:22]
c=byte_list[22:32]

inital_state_list=[a,b,c]
inital_paramaters=[]
for i in inital_state_list:
    inital_paramaters.append(normalized_value(i))

print("\n\n",inital_paramaters,"\n\n")


# Specify the output file path
output_file_path = 'inital_paramaters.txt'

# Write the hex strings to a text file
with open(output_file_path, 'w') as file:
    for hex_string in inital_paramaters:
        file.write(str(hex_string) + '\n')


print(f"inital_paramaters saved to '{output_file_path}'")



