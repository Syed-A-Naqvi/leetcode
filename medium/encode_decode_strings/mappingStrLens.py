# linear encoding and decoding
    # create encoding of the form:
        # 'string1-len(string1):'
        # 'string2string1-len(string1):len(string2):
        # ...
        # iterate from the end to find '-'
        # use one pointer to track the individual strings, use another pointer to track numbers
        # append strings to output list using corresponding numbers
    # encode Time: O(m) where m is the total number of strings in the input array
    # encode Space: O(n) where n in the total number of characters in the array
    # decode Time: O(n) where n is the total number of characters in the string
    # decode Time: O(n) where n is the total number of characters in the array
        
         
        

class Solution:
    
    def encode(self, strs: list[str]) -> str:
        
        encoded = "-"
        
        for s in strs:
            encoded = s + encoded + str(len(s)) + ":"
            
        return encoded
    
    
    def decode(self, string: str) -> list[str]:
        
        i = len(string) - 1
        while(string[i] != '-'):
            i -= 1
        
        decoded = []
        
        n = i + 1
        i -= 1
        
        while( n < len(string)):
            
            number = ""
            while(string[n] != ':'):
                number = number + string[n]
                n += 1
            n += 1

            s = ""
            for _ in range(int(number)):
                s = string[i] + s
                i -= 1
            
            decoded.append(s)
        
        return decoded
    

Input = ["neet","code","love","you"]
print(f"input = {Input}")
print(f"encoded = {Solution().encode(Input)}")
print(f"decoded = {Solution().decode(Solution().encode(Input))}")