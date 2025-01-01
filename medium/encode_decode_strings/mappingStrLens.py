class Solution:
    
    def encode(strs: list[str]) -> str:
        
        encoded = "-"
        
        for s in strs:
            encoded = s + encoded + str(len(s)) + ":"
    
    
    def decode(str: str) -> list[str]:
        pass