import requests 

print("ansh devloper".center(67,"-",),"\n")
url = "http://localhost:8000/"

re = requests.get(url)
if(re.status_code==200):
    print("server running".center(67))
else:
    print("server not working")
findurl = "http://localhost:8000/find/"
def home():
    re = requests.get(url)
    print("(home) ansh api".center(67,"-"))
    print(f"status code: {re.status_code}".center(67))
    print(f"response: {re.text}".center(67))
    return "done"
    
def adduser(name,email,ID):
    print("adding user".center(67))
    data = {"name":name,"email":email,"id":ID}
    re = requests.post(f"{url}adduser",json=data)
    print(f"status code: {re.status_code}".center(67))
    print(f"details\nuser name: {name}\nemail: {email}\nid: {ID}")
    return "done"
    
    
def finduser(ID):
    print("(search) ansh api".center(67))
    re = requests.get(f"{findurl}{int(ID)}")
    print(f"status code: {re.status_code}\n")
    print(f"response".center(67))
    print(f"{re.text}".center(67))
    return "done".center(67)


while True:
    command = input("\nenter command: ")
    if(command.lower()=="home"):
        print("\n")
        home();
        print("".center(67,"-"),"\n")
    elif(command.lower()=="add user"):
        print("\n")
        Name = input("enter name: ")
        Email = input("enter email: ")
        ID = int(input("enter id: "))
        adduser(name=Name,email=Email,ID=ID)
        print("".center(67,"-"),"\n")
    elif(command.lower()=="find user"):
        print("\n")
        IDs = int(input("enter id: "))
        finduser(IDs)
        print("".center(67,"-"))
        
    elif(command.lower()=="exit"):
        print("\n")
        print("task completed".center(67,"+"))
        break
    else:
        print("wrong command".center(67))
        
