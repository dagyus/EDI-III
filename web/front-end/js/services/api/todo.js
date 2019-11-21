export const requestApi = data => {
    return fetch("http://localhost",
        {
            method: "POST",
            body: data,
            header: {
                'Content-Type': "application/json"
            }
        }
    );
};