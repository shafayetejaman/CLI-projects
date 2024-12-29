// Get the current URL

// let url = "https://4anime.cc/anime-online/arifureta-shokugyou-de-sekai-saikyou-2nd-season-dub/013";
let url = new URL(window.location.href);

// Get the path parts as an array
let pathParts = url.pathname.split('/');

// Find the last part that's a number and increment it
for (let i = pathParts.length - 1; i >= 0; i--)
{
    if (!isNaN(pathParts[i]) && pathParts[i] !== "")
    {
        const s = String(parseInt(pathParts[i]) + 1);
        pathParts[i] = s.padStart(pathParts[i].length, "0");
        break;
    }
}

// Rebuild the new path and set it as the new URL
url.pathname = pathParts.join('/');
console.log(pathParts[pathParts.length - 1])

// episode-012";
if (!document.querySelector(`#episode-${pathParts[pathParts.length - 1]}`)) // Check if the element exists
{b
    prompt("Not found!");
    return;
}

// Redirect to the new URL
window.location.href = url.href;
