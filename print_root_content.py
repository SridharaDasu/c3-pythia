import sys
import uproot
input_file = "pytree.root"
input = uproot.open(input_file)
events = input["Event"]
info = input["Info"]
print(f"Content of the file {input_file}")
print('The content of the events = input["Event"] is:')
for item in events.items():
    print(item[0])
print('The content of the events = input["Info"] is:')
for item in info.items():
    print(item[0])
print('You can access the elements as array = events["entry"]["pSave"]["tt"].array()')
print('Similarly array = info["eCMsubSave"]')
print("You may want to use np.squeeze(array)")
