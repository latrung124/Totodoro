import os
import subprocess
import urllib.request
import sys
from pathlib import Path

# Settings
JAR_URL = "https://repo1.maven.org/maven2/org/openapitools/openapi-generator-cli/7.8.0/openapi-generator-cli-7.8.0.jar"
JAR_FILE = "openapi-generator-cli.jar"
OPENAPI_DIR = Path("openapi")          # Folder containing *.json OpenAPI specs
OUTPUT_BASE = Path("generated")        # Base folder for generated clients
GENERATOR = "cpp-qt-client"           # Change to "cpp-restsdk" if you prefer Casablanca

def download_jar():
    if not os.path.exists(JAR_FILE):
        print(f"⬇️ Downloading OpenAPI Generator CLI from {JAR_URL}...")
        urllib.request.urlretrieve(JAR_URL, JAR_FILE)
        print("✅ Download completed.")
    else:
        print("ℹ️ JAR already exists, skipping download.")

def generate_for_spec(spec_file: Path):
    service_name = spec_file.stem  # e.g., "task_management_service"
    output_dir = OUTPUT_BASE / f"{service_name}_client"

    cmd = [
        "java", "-jar", JAR_FILE, "generate",
        "-i", str(spec_file),
        "-g", GENERATOR,
        "-o", str(output_dir)
    ]

    print(f"🚀 Generating client for {spec_file.name} → {output_dir}")
    result = subprocess.run(cmd, capture_output=True, text=True)

    if result.returncode == 0:
        print(f"✅ Successfully generated client for {service_name}")
    else:
        print(f"❌ Failed to generate client for {service_name}")
        print("STDOUT:", result.stdout)
        print("STDERR:", result.stderr)
        sys.exit(result.returncode)

def main():
    download_jar()

    if not OPENAPI_DIR.exists():
        print(f"❌ OpenAPI folder {OPENAPI_DIR} not found.")
        sys.exit(1)

    specs = list(OPENAPI_DIR.glob("*.json"))
    if not specs:
        print(f"⚠️ No OpenAPI JSON files found in {OPENAPI_DIR}")
        sys.exit(0)

    for spec in specs:
        generate_for_spec(spec)

if __name__ == "__main__":
    main()
