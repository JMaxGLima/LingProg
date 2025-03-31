from ctypes import windll, Structure, c_long, byref
import time
import msvcrt

class Point(Structure):
    _fields_ = [("x", c_long), ("y", c_long)]  

def query_mouse_position():
    pt = Point()
    windll.user32.GetCursorPos(byref(pt))
    return {"x": pt.x, "y": pt.y}

if __name__ == "__main__":
    resolution_x = 1980
    resolution_y = 1080
    
    while True:
        pos = query_mouse_position()
        print("Mouse Position: x=%d, y=%d" % (pos["x"], pos["y"]))
        time.sleep(0.1)  # Adjust delay as needed
        
        if pos["x"] < (resolution_x/2) and pos["y"] < (resolution_y/2):
            print("Quadrant A")
        elif pos["x"] >= (resolution_x/2) and pos["y"] < (resolution_y/2):
            print("Quadrant B")
        elif pos["x"] < (resolution_x/2) and pos["y"] >= (resolution_y/2):
            print("Quadrant C")
        else:
            print("Quadrant D")
            
        if msvcrt.kbhit():
            if msvcrt.getch() == b'\x1b':
                break