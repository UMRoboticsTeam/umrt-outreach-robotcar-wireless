import gzip
import io
import sys
import re

TEXT_FILE = "index_ov3660_html_gz.txt"
HTML_FILE = "index_ov3660.html"

def txt_to_html():
    with open(TEXT_FILE, "r") as f:
        hex_string = f.read()

    # hex to byte data
    hex_values = re.findall(r'0x([0-9A-Fa-f]{2})', hex_string)
    byte_data = bytes(int(h, 16) for h in hex_values)

    # decompress from gz
    with gzip.GzipFile(fileobj=io.BytesIO(byte_data), mode='rb') as gz:
        html = gz.read().decode('utf-8')

    with open(HTML_FILE, "w", encoding="utf-8") as f:
        f.write(html)

    print(f"[✔] Decompressed HTML saved as: {HTML_FILE}")


def html_to_txt():
    with open(HTML_FILE, "r", encoding="utf-8") as f:
        html = f.read()

    buf = io.BytesIO()
    with gzip.GzipFile(fileobj=buf, mode='wb', mtime=0) as gz:
        gz.write(html.encode('utf-8'))

    byte_data = buf.getvalue()
    size = len(byte_data)

    
    lines = []
    for i in range(0, size, 16):
        chunk = byte_data[i:i+16]
        line = ", ".join(f"0x{b:02X}" for b in chunk)
        lines.append(f"    {line}")

    hex_data = ",\n".join(lines)

    with open(TEXT_FILE, "w") as f:
        f.write(f"//File: index_ov3660.html.gz_CEP, Size: {size}\n")
        f.write(f"#define index_ov3660_html_gz_len_CEP {size}\n")
        f.write(f"const uint8_t index_ov3660_html_gz_CEP[] = {{\n")
        f.write(hex_data)
        f.write("\n};\n")

    print(f"[✔] Header-style GZ data written to: {TEXT_FILE}")



def main():
    if len(sys.argv) != 2 or sys.argv[1] not in ["txt_to_html", "html_to_txt"]:
        print("Usage: python converter.py [txt_to_html|html_to_txt]")
        return

    if sys.argv[1] == "txt_to_html":
        txt_to_html()
    else:
        html_to_txt()


if __name__ == "__main__":
    main()
