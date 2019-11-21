export const requestApi = data => {
    fetch("http://localhost",
        {
            method: "POST",
            body: data,
            header: {
                'Content-Type': "application/json"
            }
        })
        .then(res => res.json())
        .catch(err => { throw new Error(err) });
};